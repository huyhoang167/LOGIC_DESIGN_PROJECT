/* 
 * File:   global.h
 * Author: Hoang
 *
 * Created on November 25, 2022, 10:23 PM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

#include <p18f4620.h>

extern int status;
extern char hour;
extern char minute;
extern char second;
extern unsigned char day;
extern char date;
extern char month;
extern char year;
extern unsigned char count ;
extern int format_12h;
extern int format_24h;
extern int isPM_or_AM ; //PM = 1, AM = 0;
extern int count1;
//extern char menu[]; 

extern int x ;
extern int y ;
extern int count3;
extern unsigned int k;
extern char*day_week[7];
extern int num_countries;
extern int country;
extern int last_country;
extern unsigned char* countries[5];
extern int world_time[5];
extern int index_worldtime;
extern int index_set;
extern int day_of_month[12];
extern int blink_flag;
extern int blink_count;
extern int counter[4];
extern int turn_counter;
extern int hour_alarm;
extern int minute_alarm;
extern int alarm_flag;
extern int index_animation;
extern int index_animation_set;
extern int animation_menu_size;
extern unsigned char* animation_menu[2];
extern int big_num;
extern int flag_animation_menu;
extern int focus[3];
extern int index_focus;
extern int flag_focus_run;
extern int second_focus;
extern int flag_alarm_blink;
extern int flag_press;
/*
 INIT: Trang thai khoi tao
 MODE_1: Hien gio
 MODE_2: Mo menu
 MODE_3: Chinh gio
 MODE_4: Bam gio
 MODE_5: Gio the gioi
 */
#define INIT 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4
#define MODE_5 5
#define MODE_6 6
#define MODE_7 7
#define MODE_8 8
#define MODE_9 9
#define MODE_10 10
#define MODE_11 11
#define     ADDRESS_SECOND  0x00
#define     ADDRESS_MINUTE  0x01
#define     ADDRESS_HOUR    0x02
#define     ADDRESS_DAY     0x03
#define     ADDRESS_DATE    0x04
#define     ADDRESS_MONTH   0x05
#define     ADDRESS_YEAR    0x06

#define buzzer TRISCbits.RC2
extern int buzzer_flag;
#endif	/* GLOBAL_H */

