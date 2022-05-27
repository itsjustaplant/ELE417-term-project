/*
 * wifi.c
 *
 *  Created on: May 27, 2022
 *      Author: alperen
 */

#include "wifi.h"
#include "utility.h"

#define Enable_RX_Interrupt    IE2 |= UCA0RXIE;
#define Disable_RX_Interrupt   IE2 &= ~UCA0RXIE;

char transmitter_buffer[100]; // buffer for tx
char receiver_buffer[100];    // buffer for rx
char *protocol_name = "MQTT";


void ConnectWifi(char *ssid ,char *password){

    UARTTransmitString("AT+RST\r\n",(unsigned short)strlen("AT+RST\r\n"));
    Enable_RX_Interrupt;
    MSDelay(15);
    while(!(IsReceiveSendOK())){
        UARTTransmitString("AT+RST\r\n",(unsigned short)strlen("AT+RST\r\n"));
        Enable_RX_Interrupt;
        MSDelay(15);
    }
    MSDelay(1000);

    UARTTransmitString("AT\r\n",(unsigned short)strlen("AT\r\n"));
    Enable_RX_Interrupt;
    MSDelay(15);
    while(!(IsReceiveSendOK())){
        UARTTransmitString("AT\r\n",(unsigned short)strlen("AT\r\n"));
        Enable_RX_Interrupt;
        MSDelay(15);
    }

    UARTTransmitString("AT+CWMODE=1\r\n",(unsigned short)strlen("AT+CWMODE=1\r\n"));
    Enable_RX_Interrupt;
    MSDelay(10);
    while(!(IsReceiveSendOK())){
        UARTTransmitString("AT+CWMODE=1\r\n",(unsigned short)strlen("AT+CWMODE=1\r\n"));
        Enable_RX_Interrupt;
        MSDelay(10);
    }

    sprintf(transmitter_buffer,"AT+CWJAP=\"%s\",\"%s\"\r\n",ssid,password);
    UARTTransmitString(transmitter_buffer,strlen(transmitter_buffer));
    CleanTransmitterBuffer();
    MSDelay(2000);
    CleanReceiverBuffer();
}

void ConnectServer(char *IP, char *port){

    UARTTransmitString("AT+CIPCLOSE\r\n",(unsigned short)strlen("AT+CIPCLOSE\r\n"));
    Enable_RX_Interrupt;
    MSDelay(1000);
    while(!(IsReceiveSendOK())){
        UARTTransmitString("AT+CIPCLOSE\r\n",(unsigned short)strlen("AT+CIPCLOSE\r\n"));
        Enable_RX_Interrupt;
        MSDelay(1000);
    }

    UARTTransmitString("AT+CIPMUX=0\r\n",(unsigned short)strlen("AT+CIPMUX=0\r\n"));
    Enable_RX_Interrupt;
    MSDelay(1000);
    while(!(IsReceiveSendOK())){
        UARTTransmitString("AT+CIPMUX=0\r\n",(unsigned short)strlen("AT+CIPMUX=0\r\n"));
        Enable_RX_Interrupt;
        MSDelay(1000);
    }

    unsigned short Length = sprintf(transmitter_buffer,"AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",IP,port);
    UARTTransmitString(transmitter_buffer,Length);
    Enable_RX_Interrupt;
    MSDelay(2000);
    while(!(IsReceiveSendOK())){
        UARTTransmitString(transmitter_buffer,Length);
        Enable_RX_Interrupt;
        MSDelay(2000);
    }
    CleanTransmitterBuffer();
}

void ConnectBroker(char *ClientID, char *UserName, char *UserPassword){

    uint16_t KeepAlive = 100;
    uint8_t  Connect = 0x10;
    uint8_t  Level = 0x04;
    uint8_t  Flag = 0xC2;
    uint16_t ProtocolNameLength = strlen(protocol_name);
    uint16_t ClientIDLength = strlen(ClientID);
    uint16_t UserNameLength = strlen(UserName);
    uint16_t UserPasswordLength = strlen(UserPassword);

    uint8_t RemainLength = 2 + ProtocolNameLength + 6 + ClientIDLength + 2 + UserNameLength + 2 + UserPasswordLength;
    uint16_t TotalLength = sprintf(transmitter_buffer,"%c%c%c%c%s%c%c%c%c%c%c%s%c%c%s%c%c%s",(char)Connect,(char)RemainLength,(char)(ProtocolNameLength << 8),(char)ProtocolNameLength, protocol_name,(char)Level,(char)Flag,(char)(KeepAlive << 8),(char)KeepAlive,(char)(ClientIDLength << 8),(char)ClientIDLength,ClientID,(char)(UserNameLength<<8),(char)UserNameLength,UserName,(char)(UserPasswordLength<<8),(char)UserPasswordLength,UserPassword);

    CleanTransmitterBuffer();
    sprintf(transmitter_buffer,"AT+CIPSEND=%d\r\n",TotalLength);
    UARTTransmitString(transmitter_buffer, (unsigned short)TotalLength);
    CleanTransmitterBuffer();
    MSDelay(100);
    CleanReceiverBuffer();

    sprintf(transmitter_buffer,"%c%c%c%c%s%c%c%c%c%c%c%s%c%c%s%c%c%s",(char)Connect,(char)RemainLength,(char)(ProtocolNameLength << 8),(char)ProtocolNameLength,protocol_name,(char)Level,(char)Flag,(char)(KeepAlive << 8),(char)KeepAlive,(char)(ClientIDLength << 8),(char)ClientIDLength,ClientID,(char)(UserNameLength<<8),(char)UserNameLength,UserName,(char)(UserPasswordLength<<8),(char)UserPasswordLength,UserPassword);
    UARTTransmitString(transmitter_buffer, (unsigned short)TotalLength);
    CleanTransmitterBuffer();
    MSDelay(100);
    CleanReceiverBuffer();
}


