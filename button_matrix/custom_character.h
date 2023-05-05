/* 
 * File:   custom_character.h
 * Author: Hoang
 *
 * Created on December 1, 2022, 2:51 PM
 */

#ifndef CUSTOM_CHARACTER_H
#define	CUSTOM_CHARACTER_H

#include <p18f4620.h>
#include <stdlib.h>
#include "button.h"
#include "global.h"
#include "../timer/timer.h"
#include "../lcd/lcd.h"
#include "../interrupt/interrupt.h"
#include "i2c.h"
#include "../button_matrix/animation_data.h"
extern int flag_animation;
extern count5;
extern count6; 
void custom_char();
void Display_0(char row, char column);
void Display_1(char row, char column);
void Display_2(char row, char column);
void Display_3(char row, char column);
void Display_4(char row, char column);
void Display_5(char row, char column);
void Display_6(char row, char column);
void Display_7(char row, char column);
void Display_8(char row, char column);
void Display_9(char row, char column);
void LCD_Erase(char row, char column);
void Display_big_number(char row, char column, char number);
void custom_char_animation(char data0[],char data1[],char data2[],char data3[],char data4[],char data5[]);
void Display_animation();
void Animation_to_right(char row,char column);
void Animation_to_left(char row,char column);
void wave_animation();
#endif	/* CUSTOM_CHARACTER_H */

