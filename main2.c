#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "wifi.h"
#include "utility.h"
#include "mqtt.h"

#include "lcd.h"

//https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
//https://mehmettopuz.net/esp8266-ve-stm32-ile-mqtt-protokolu/.html

char transmitter_buffer[100]; // buffer for tx
char receiver_buffer[100];    // buffer for rx
char degree_buffer[100];      // buffer for degree from mqtt

char* ssid = "Alperen";
char* password = "12345678";

char* server = "iot.ee.hacettepe.edu.tr";
char* port = "1883";

char* mqtt_username = "g33mas";
char* mqtt_password = "23fa";

int main(void){

    WDTCTL = WDTPW | WDTHOLD;            // Stop wdt+
    DCOCTL = 0;                          // Select lowest DCO settings
    BCSCTL1 = CALBC1_1MHZ;               // Set DCO to 1 MHz
    DCOCTL = CALDCO_1MHZ;

    ADC10CTL0 = SREF_0 + ADC10SHT_2 + ADC10ON;
    ADC10CTL1 = INCH_6 | SHS_0 | ADC10DIV_0 | CONSEQ_0;
    ADC10AE0 |= BIT6;

    StartTimer();                       // Start timer
    StartUART();                        // Start UART to control esp

    ConnectWifi(ssid, password);  // Connect to AP point
    ConnectServer(server, port);    // les connect to server
    ConnectBroker(mqtt_username, mqtt_username, mqtt_username);        // connect to mqtt server with given password and username

    while (1){
        ADC10CTL0 |= ENC + ADC10SC;
        temperature = (ADC10MEM*100)/1024;
        Publish("g33mas", temperature);
        __delay_cycles(2400000);
    }

}

