/*
 * utility.c
 *
 *  Created on: May 28, 2022
 *      Author: alperen
 */

#include "utility.h"

char transmitter_buffer[100];
char receiver_buffer[100];

unsigned volatile int SecondCounter_in_ms = 0;
unsigned short UartRX_Counter = 0;

void StartTimer(void){                      // Use Timer0 A0 for LPM delays
    TA0CTL = TASSEL_2 + TACLR + ID_0 ;    // Clock->SMCLK,
    TA0CCR0 = 1000-1;                     // 1ms Timing
    TA0CCTL0 |= CCIE;                     // Enable Capture/Compare Interrupt for Timer1 A0
}

void StartUART(void){
    P1SEL= BIT1 + BIT2;     // P1.1=RXD P1.2=TXD
    P1SEL2= BIT1 + BIT2;

    UCA0CTL1 |= UCSWRST;
    UCA0CTL0 = 0x00;
    UCA0CTL1 |= UCSSEL_2 | UCSWRST ;
    UCA0MCTL = UCBRF_0 | UCBRS_6;
    UCA0BR0  = 8;
    UCA0BR1  = 00;
    UCA0CTL1 &= ~UCSWRST;

    Disable_RX_Interrupt;
}

void UARTTransmitString(char *String, unsigned short Length){
    Disable_RX_Interrupt;
    unsigned short UartTX_Counter = 0;
    while(UartTX_Counter < Length){
        UARTTransmitChar(*String++);
        UartTX_Counter++;
    }
    Enable_RX_Interrupt;
}


void UARTTransmitChar(char Char){
    while(!(IFG2&UCA0TXIFG));       // USCI_A0 TX Buffer Ready?
    UCA0TXBUF = Char;               // Char -> TX
}

void MSDelay(int Milisecond){
    SecondCounter_in_ms = Milisecond;
    TA0CTL |= MC_1;                     // Start Timer for Small Delay
    __bis_SR_register(LPM1_bits + GIE); // Sleep During Delay
}

void CleanReceiverBuffer(void){
    unsigned short Buffer = 0;
    for(Buffer=0;Buffer<100;Buffer++){
        receiver_buffer[Buffer] = 0;
    }
}

void CleanTransmitterBuffer(void){
    unsigned short Buffer;
    for(Buffer=0;Buffer<100;Buffer++){
        transmitter_buffer[Buffer] = 0;
    }
    SecondCounter_in_ms = 0;
}

unsigned int IsReceiveSendOK(void){
    unsigned short Buffer_Counter = 0;
    unsigned int OKFlag = 0 ;
    while(1){
        if(receiver_buffer[Buffer_Counter]=='O' && receiver_buffer[Buffer_Counter+1]=='K'){
            OKFlag = 1 ;
            break;
        }
        Buffer_Counter++;
        if(Buffer_Counter == 99){
            UartRX_Counter=0;
            break;
        }
    }
    CleanReceiverBuffer();
    return OKFlag;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void Delay(void){
    SecondCounter_in_ms--;
    if(SecondCounter_in_ms == 0){
        TA0CTL &= ~(BIT4 + BIT5);           // Delay is Complete, Disable Counting Mode
        TA0CTL |= TACLR;                    // Clear Timer for the Next Usage
        __bic_SR_register_on_exit(CPUOFF);  // Disable Sleep Mode to Cont. Operation
    }
}

#pragma vector = USCIAB0RX_VECTOR         // UART RX Interrupt Vector
__interrupt void USCI0RX_ISR(void){
    if(UartRX_Counter<100){
        receiver_buffer[UartRX_Counter] = UCA0RXBUF;
        if(UartRX_Counter>0){
            if(receiver_buffer[UartRX_Counter-1]=='O' && receiver_buffer[UartRX_Counter]=='K'){   // If the RX send OK
                Disable_RX_Interrupt;
                UartRX_Counter = 0;
                P1OUT ^= BIT0;         // Control LED
            }
        }
    }
    UartRX_Counter++;
}
