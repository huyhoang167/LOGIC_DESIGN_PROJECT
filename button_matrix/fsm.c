#include "fsm.h"
#include "custom_character.h"
#include "../timer/timer.h"
#include "clock.h"
#include "global.h"
char Bell[8] = {0b00100,0b01110,0b01110,0b01110,0b11111,0b00000,0b00100,0b00000};
void fsm(){
    switch(status){
        case INIT:
            status = MODE_1;
            Read_time();
            break;
        case MODE_1:
            if (is_key_down(13)){
                status = MODE_2;
                big_num = 0;
                break;
            }
            if (is_key_down(2)){
                big_num = 1;
                custom_char_num();
            }
            if (is_key_down(12)){
                big_num = 0;
            }
            if (is_key_down(5)){
                alarm_flag = 0;
            }
            LcdClearS();
            is_12h_format();
            is_24h_format();
            Read_time();
            if (alarm_flag == 1){
                int n;
                lcd_write_cmd(64);
                for (n = 0; n<=7; n++) lcd_write_data(Bell[n]);   
                LcdPrintCharS(1,15,0);
     
            }
            if (hour == hour_alarm && minute == minute_alarm && alarm_flag == 1 && second <= 10){
                LcdClearS();
                LcdPrintStringS(0,4,"TIME-OUT");
                LcdPrintStringS(1,0,"HAY TAT BAO THUC");
                PORTCbits.RC2 = 0;
                if (flag_alarm_blink == 1){
                    LcdPrintStringS(0,3,"         ");
                    LcdPrintStringS(1,0,"                ");
                    flag_alarm_blink = 0;
                    
                }
                if (buzzer_flag == 1){
                        PORTCbits.RC2 = 1;
                        buzzer_flag = 0;
                }
                if (is_key_down(5)){
                    alarm_flag = 0;
                }
                if (second == 10){
                    alarm_flag = 0;
                   PORTCbits.RC2 = 0;
                }
                DisplayLcdScreen();
            }
            else{
                if (big_num == 1){
                    Display_time_big_num();
                }
                else{
                    Display_time();
                    Display_Date();
                    DisplayLcdScreen();
                }
            }
            break;
        case MODE_2:
            display_menu();
            if (is_key_down(0)){
                status = MODE_1;
                y = 0; 
                k = 0;
                break;
            }
            if (is_key_down(1)){
                status = MODE_3;
                y = 0; 
                k = 0;
                break;
            }
            if (is_key_down(2)){
                status = MODE_4;
                y = 0; 
                k = 0;
                break;
            }
            if (is_key_down(4)){
                status = MODE_5;
                y = 0; 
                k = 0;
                break;
            }
            if (is_key_down(5)){
                status = MODE_6;
                y = 0; 
                k = 0;
                break;
            }
            if (is_key_down(6)){
                status = MODE_7;
                y = 0; 
                k = 0;
                break;
            }
             if (is_key_down(8)){
                y = 0; 
                k = 0;
                status = MODE_8;
                flag_animation_menu = 1;
                break;
            }
            if(is_key_down(9)){
                status = MODE_9;
                second_focus = -1;
                focus[0] = 0;
                focus[1] = 0;
                focus[2] = 0;
                index_focus = 0;
                flag_focus_run = 0;
                break;
            }
            if (is_key_down(10)){
                status = MODE_10;
                break;
            }
            break;
        case MODE_3:
            if (is_key_down(13)){
                status = MODE_2;
                break;
            }
            if(is_key_down(12)){
                status = MODE_1;
                Set_Time();
//                index_worldtime = 0;
                break;
            }
            if(is_key_down(6)){
                index_worldtime++;
                if(index_worldtime > num_countries-1){
                     index_worldtime = num_countries-1;
                }
            }
            if(is_key_down(4)){
                index_worldtime--;
                if(index_worldtime < 0){
                    index_worldtime = 0;
                }
            }
            if(is_key_down(5)){
                country = index_worldtime;
            }
            if(country != last_country){
                //Update world time by Phuc
                hour = hour - world_time[last_country]+world_time[country];
                if(hour < 0){
                    day--;
                    if(day == 0) day = 7;
                    date = date-1;
                    if(date == 0){
                        month--;
                        if(month == 0) month = 12;
                        date = day_of_month[month-1];
                        if(month == 12) year--;
                    }
                }
                else if(hour >= 24){
                    day++;
                    if(day == 8) day = 1;
                    date++;
                    if(date > day_of_month[month]){
                        date = 1;
                        month++;
                        if(month == 13){
                            month = 1;
                            year++;
                        }
                    }
                }
                //Update world time by Phuc
                hour = (hour+24)%24;
                last_country = index_worldtime;
            }
            LcdClearS();
            display_worldtime();
            DisplayLcdScreen();
            break;
        case MODE_4:
            if (is_key_down(13)){
                status = MODE_2;
                break;
            }
            if (is_key_pressed(0)){
                index_set = (index_set+1)%8;
                if (index_set == 0) index_set++;
            }
            if (is_key_pressed(6)){
                increase();
                flag_press = 1;
            }
            if (is_key_pressed(4)){
                decrease();
                flag_press = 1;
            }
            if (is_key_down(5)){
                status = MODE_1;
                Set_Time();
                break;
            } 
            LcdClearS();
            Display_inc_and_dec_mode();
            DisplayLcdScreen();
            flag_press = 0;
            break;
        case MODE_5: 
            if (is_key_down(13)){
                status = MODE_2;
                break;
            }
            Day_Week_Number();
            break;
        case MODE_6: 
            if (is_key_down(13)){
                status = MODE_2;
                break;
            }
            if(is_key_down(5)){
                turn_counter = 1-turn_counter;
            }
            if(!turn_counter && is_key_down(6)){
                counter[0] = 0;
                counter[1] = 0;
                counter[2] = 0;
                counter[3] = 0;
            }
            LcdClearS();
            display_counter();
            DisplayLcdScreen();
            break;
        case MODE_7: 
            if (is_key_down(13)){
                status = MODE_2;
                break;
            }
            Alarm();
            break;
        case MODE_8: 
            if (is_key_pressed(13)){
                status = MODE_2;
                index_animation_set = -1;
                flag_animation = 1;
                count5 = 0;
                count6 = 0;
                break;
            }
            Display_animation_menu();
            break;
        case MODE_9:
            if(flag_focus_run == 1){
                focus_run();
                Display_focus();
                if(focus[0] == 0 && focus[1] == 0){
                    flag_focus_run = 0;
                    index_focus = 0;
                }
            }
            else{
                Display_focus();
                if(is_key_down(0)){
                    index_focus = (index_focus+1)%3;
                }
                if(is_key_pressed(6)){
                    if(index_focus == 1){
                        focus[0] = (focus[0]+1)%60;
                    }
                    else if(index_focus == 2){
                        focus[1] = (focus[1]+1)%60;
                    }
                }
                if(is_key_pressed(4)){
                    if(index_focus == 1){
                        focus[0] = (focus[0]-1+60)%60;
                    }
                    else if(index_focus == 2){
                        focus[1] = (focus[1]-1+60)%60;
                    }
                }
                if(is_key_down(5)){
                    index_focus = 0;
                    flag_focus_run = 1;
                }
                if(is_key_down(13)){
                    status = MODE_2;
                    LcdClearS();
                    index_focus = 0;
                    flag_focus_run = 0;
                }
            }
            break;
        case MODE_10:
            if (is_key_down(13)){
                status = MODE_2;
                clear_game_mode();
                break;
            }
            Display_game();
            DisplayLcdScreen();
            break;  
        default:
            break;
    }
           
}
