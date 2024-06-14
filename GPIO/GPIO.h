/* 
 * File:   GPIO.h
 * Author: moham
 *
 * Created on June 13, 2024, 4:32 PM
 */

#ifndef GPIO_H
#define	GPIO_H

#include <xc.h>
// Initializes the GPIO pin configuration
void GPIO_Init(void);

// Writes a value to the specified GPIO pin
void GPIO_Write(unsigned char PinId, unsigned char PinData);

#endif	/* GPIO_H */

