/* 
 * File:   clock.h
 * Author: Hoang
 *
 * Created on November 25, 2022, 10:25 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <p18f4620.h>
#include "button_matrix/button.h"
#include "button_matrix/global.h"
#include "timer/timer.h"
#include "lcd/lcd.h"
#include "interrupt/interrupt.h"
#include "i2c.h"
void init_system(void);
void Display_time();
void Display_inc_and_dec_mode();
void Display_Date();
void Read_time();
void Set_Time();
void Increase();
void display_menu();
void increase();
void decrease();
void display_worldtime();
void Day_Week_Number();
void Alarm();
void Display_alarm();
void Display_animation_menu();

void focus_run();
void Display_focus();

#endif	/* CLOCK_H */

