/*
 * wifi.h
 *
 *  Created on: May 27, 2022
 *      Author: alperen
 */

#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "definition.h"

void ConnectWifi(char *SSID ,char *Password);

void ConnectServer(char *IP ,char *Port);

void ConnectBroker(char *ClientID, char *UserName, char *UserPassword);


