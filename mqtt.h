/*
 * mqtt.h
 *
 *  Created on: May 28, 2022
 *      Author: alperen
 */

#include <msp430.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#ifndef MQTT_H_
#define MQTT_H_

void Publish(char *Topic, char *Message);

char* Subscribe(char *Topic);

#endif /* MQTT_H_ */
