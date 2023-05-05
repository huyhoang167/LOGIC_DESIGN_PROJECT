/* 
 * File:   DHT11.h
 * Author: Hoang
 *
 * Created on December 15, 2022, 2:22 PM
 */

#ifndef DHT11_H
#define	DHT11_H

#include <p18f4620.h>
#define DHT11_Data_Pin   PORTDbits.RD5
#define DHT11_Data_Pin_Direction  TRISDbits.TRISD5

extern char Check_bit;

void DHT11_Start();
void DHT11_Check_Response();
char read_data();

#endif	/* DHT11_H */

