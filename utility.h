/*
 * utility.h
 *
 *  Created on: May 28, 2022
 *      Author: alperen
 */

#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "definition.h"

#ifndef UTILITY_H_
#define UTILITY_H_

void StartTimer(void);
void StartUART(void);
void UARTTransmitString(char *String, unsigned short Length);
void UARTTransmitChar(char Char);
void MSDelay(int Milisecond);
void CleanReceiverBuffer(void);
void CleanTransmitterBuffer(void);
unsigned int IsReceiveSendOK(void);


#endif /* UTILITY_H_ */
