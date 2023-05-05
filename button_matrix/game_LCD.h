/* 
 * File:   game_LCD.h
 * Author: Hoang
 *
 * Created on January 7, 2023, 11:57 PM
 */

#ifndef GAME_LCD_H
#define	GAME_LCD_H

#include <p18f4620.h>
#include "button_matrix/button.h"
#include "button_matrix/global.h"
#include "timer/timer.h"
#include "lcd/lcd.h"

 char dino_l[8] = {0b00000111, 0b00000101, 0b00000111, 0b00010110, 0b00011111, 0b00011110, 0b00001110, 0b00000100};
 char dino_r[8] = {0b00000111, 0b00000101, 0b00000111, 0b00010110, 0b00011111, 0b00011110, 0b00001110, 0b00000010};
 char cactus_small[8] = {0b00000000,0b00000000,0b00000100,0b00000101,0b00010101,0b00010110,0b00001100,0b00000100};
 char cactus_big[8] = {0b00000000, 0b00000100, 0b00000101, 0b00010101, 0b00010110,0b00001100,0b00000100,0b00000100};
 char sad_face[8] = {0b00000,0b00000,0b01010,0b00000,0b01110,0b10001,0b00000,0b00000};
 char happy_face[8] = {0b00000,0b00000,0b01010,0b00000,0b10001,0b01110,0b00000,0b00000};
 char play[8] = {0b10000,0b11000,0b11100,0b11110,0b11100,0b11000,0b10000,0b00000};
 
#define READY 101
#define PLAY 102
#define GAME_OVER 103
#define WIN 104
#endif	/* GAME_LCD_H */

