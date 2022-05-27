/*
 * mqtt.c
 *
 *  Created on: May 28, 2022
 *      Author: alperen
 */

#include "mqtt.h"

char TX_Buffer[100];
char RX_Buffer[100];

uint16_t PacketID = 0x01;
uint8_t  PublishCon = 0x30;
uint8_t  SubscribeCon = 0x82;
uint8_t  Qos = 0x00;


void Publish(char *Topic, char *Message){

    uint8_t MessageLength = strlen(Message);
    uint16_t TopicLength = strlen(Topic);
    uint8_t  RemainLength = 2 + TopicLength + MessageLength;

    /*
      (char)PublishCon          1
      (char)RemainLength        1
      (char)(TopicLength << 8)  1
      (char)TopicLength         1
      Topic                     4
      Message                   5
    */

    unsigned short Length = sprintf(TX_Buffer,"%c%c%c%c%s%s",(char)PublishCon,(char)RemainLength,(char)(TopicLength << 8),(char)TopicLength,Topic,Message);
    UART_Transmit_String(TX_Buffer,sprintf(TX_Buffer,"AT+CIPSEND=%d\r\n",Length));
    Delay_in_ms(250);
    Clean_TXBuffer();
    Clean_RXBuffer();

    sprintf(TX_Buffer,"%c%c%c%c%s%s",(char)PublishCon,(char)RemainLength,(char)(TopicLength << 8),(char)TopicLength,Topic,Message);
    UART_Transmit_String(TX_Buffer,Length);
    Delay_in_ms(250);
    Clean_TXBuffer();

}

char* Subscribe(char *Topic){

    uint16_t TopicLength  = strlen(Topic);
    uint8_t  RemainLength = 2+2+TopicLength+1;   // packetIDlength(2) + topiclengthdata(2) + topiclength + Qos
    uint16_t Length = sprintf(TX_Buffer,"%c%c%c%c%c%c%s%c",(char)SubscribeCon,(char)RemainLength,(char)(PacketID << 8),(char)PacketID,(char)(TopicLength << 8),(char)TopicLength,Topic,(char)Qos);

    sprintf(TX_Buffer,"AT+CIPSEND=%d\r\n",Length);
    __delay_cycles(100000);

    sprintf(TX_Buffer,"%c%c%c%c%c%c%s%c",(char)SubscribeCon,(char)RemainLength,(char)(PacketID << 8),(char)PacketID,(char)(TopicLength << 8),(char)TopicLength,Topic,(char)Qos);
    __delay_cycles(100000);
    return TX_Buffer;
}



