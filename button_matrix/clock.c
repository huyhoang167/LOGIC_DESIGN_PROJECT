#include "clock.h"
#include "i2c.h"
#include "custom_character.h"

unsigned char* animation_menu[] = {"Man Walking","Wave"};
unsigned char arrow[] = { 0x00, 0x04, 0x08, 0x1F, 0x08, 0x04, 0x00, 0x00};
char sub_year = 20;
char menu[] = "MODE1: THOI GIAN (NHAN 1)|MODE2: GIO THE GIOI (NHAN 2)|MODE 3: DIEU CHINH THOI GIAN (NHAN 3)|MODE 4: SO NGAY HIEN TAI (NHAN 4)|MODE 5: DEM GIO (NHAN 5)|MODE 6: BAO THUC (NHAN 6)|MODE 7: ANH DONG (NHAN 7)|MODE 8: CHE DO TAP TRUNG (NHAN 8)";
void Set_Time()
{

    write_ds1307(ADDRESS_SECOND, second);
    write_ds1307(ADDRESS_MINUTE, minute);
    write_ds1307(ADDRESS_HOUR, hour);
    write_ds1307(ADDRESS_DAY, day);
    write_ds1307(ADDRESS_DATE, date);
    write_ds1307(ADDRESS_MONTH, month);
    write_ds1307(ADDRESS_YEAR, year);
}
void Read_time(){
    second  = read_ds1307(ADDRESS_SECOND);
    minute = read_ds1307(ADDRESS_MINUTE);
    hour = read_ds1307(ADDRESS_HOUR);
    day = read_ds1307(ADDRESS_DAY);
    date = read_ds1307(ADDRESS_DATE);
    month = read_ds1307(ADDRESS_MONTH); 
    if (year == 99 && read_ds1307(ADDRESS_YEAR) == 0){
        sub_year++;
    }   
    year = read_ds1307(ADDRESS_YEAR);
}
void display_menu(){
    LcdPrintStringS(0,0,"Moi chon che do");
    if (flag_timer1 == 1){
        SetTimer1_ms(30);    
        LcdPrintCharS(x,y,menu[k]);
        y++;
        k++;
        if (y >= 16){
          
            count3++;
            y = 0;
            k = count3;
            DisplayLcdScreen();
            LcdClearS();
        }
          if (menu[k] == '\0'){
              y = 0;
              LcdClearS();
              LcdPrintStringS(0,0,"Moi chon che do");
              count3 = 0;
              k = count3;
          }
    }
}
int is_12h_format(){
    if (is_key_down(0)){
        format_12h = 1;
        format_24h = 0;
        return 1;
    }
    else return 0;
}
int is_24h_format(){ 
    if (is_key_down(1) != 0){
          format_24h = 1;
        return 1;
    }
    else return 0;
}
void Display_time(){
    if (format_12h == 1 && format_24h == 1){
            LcdPrintStringS(0,7,"   ");
    }
    if(format_12h == 1 && format_24h == 0){
        if (hour > 12){
            hour = hour -12;
            isPM_or_AM = 1;
            LcdPrintStringS(0,7," PM");
        }
        else if (hour == 12){
            isPM_or_AM = 1;
            LcdPrintStringS(0,7," PM");
        }
        else{
            if (hour ==0 ) hour = 12;
            isPM_or_AM = 0;
            LcdPrintStringS(0,7," AM");      
        }   
    }
        LcdPrintNumS(0,0,hour/10);
        LcdPrintNumS(0,1,hour%10);
        LcdPrintStringS(0,2,":");
        LcdPrintNumS(0,3,minute/10);
        LcdPrintNumS(0,4,minute%10);
        LcdPrintStringS(0,5,":");
        LcdPrintNumS(0,6,second/10);
        LcdPrintNumS(0,7,second%10);
        
        LcdPrintStringS(0,11,"UTC");
        if(world_time[index_worldtime] < 0){
            LcdPrintStringS(0,14,"-");
            LcdPrintNumS(0,15,-world_time[index_worldtime]);
        }
        else{
            LcdPrintStringS(0,14,"+");
            LcdPrintNumS(0,15,world_time[index_worldtime]);
        }
        
}     

void Display_Date(){
    LcdPrintStringS(1,0,day_week[day-1]);
    LcdPrintStringS(1,3,", ");
    LcdPrintNumS(1,4,date/10);
    LcdPrintNumS(1,5,date%10);
    LcdPrintStringS(1,6,"/");
    LcdPrintNumS(1,7,month/10);
    LcdPrintNumS(1,8,month%10);
    LcdPrintStringS(1,9,"/");
    LcdPrintNumS(1,10,sub_year/10);
    LcdPrintNumS(1,11,sub_year%10);
    LcdPrintNumS(1,12,year/10);
    LcdPrintNumS(1,13,year%10);
}
void display_worldtime(){   
    int n;      
    lcd_write_cmd(64);
    for (n = 0; n<=7; n++) lcd_write_data(arrow[n]); 

    if(index_worldtime == 0){
        LcdPrintStringS(0,0,"World time");
        LcdPrintStringS(1,0,countries[index_worldtime]);
        LcdPrintCharS(1,15,0);

    }
    else if(index_worldtime+1 < num_countries){
        LcdPrintStringS(0,0,countries[index_worldtime]);
        LcdPrintStringS(1,0,countries[index_worldtime+1]);
        LcdPrintCharS(0,15,0);
    }
    else{
        LcdPrintStringS(0,0,countries[index_worldtime-1]);
        LcdPrintStringS(1,0,countries[index_worldtime]);
        LcdPrintCharS(1,15,0);
    }
}
void increase(){
    switch(index_set){
        case 1: 
            hour++;
            if (hour > 23){
                hour = 0;
            }
            break;
        case 2:
            minute++;
            if (minute > 59){
                minute = 0;
            }
            break;
        case 3:
            second++;
            if (second > 59){
                second = 0;
            }
            break;
        case 4:
            day++;
            if (day > 7){
                day = 1;
            }
            break;
        case 5:
            date = date+1;
            if(date > day_of_month[month-1]){
                date = 1;
            }
            break;
        case 6:
            month++;
            if (month > 12){
                month = 1;
            }
            break;
        case 7:
            year++;
            if (year > 99){
                year = 0;
                sub_year++;
            }
            break;
        default:
            break;
    }
}
void decrease(){
    switch(index_set){
        case 1: 
            hour--;
            if (hour < 0){
                hour = 23;
            }
            break;
        case 2:
            minute--;
            if (minute < 0){
                minute = 59;
            }
            break;
        case 3:
            second--;
            if (second < 0){
                second = 59;
            }
            break;
        case 4:
            day--;
            if (day < 1){
                day = 7;
            }
            break;
        case 5:
            date = date -1;
            if(date < 1 ){
                date = day_of_month[month-1];
            }
            break;
        case 6:
            month--;
            if (month < 1){
                month = 12;
            }
            break;
        case 7:
            year--;
            if (year < 0){
                year = 99;
                sub_year--;
            }
            break;
        default:
            break;
    }
}
void Display_alarm(){
    LcdPrintNumS(1,5,hour/10);
    LcdPrintNumS(1,6,hour%10);
    if(index_set == 1 && blink_flag == 1 && flag_press == 0){
        LcdPrintStringS(1,5,"  ");
    }
    LcdPrintStringS(1,7,":");
    LcdPrintNumS(1,8,minute/10);
    LcdPrintNumS(1,9,minute%10);
    if(index_set == 2 && blink_flag == 1 && flag_press == 0){
        LcdPrintStringS(1,8,"  ");  
    }
}
void Display_inc_and_dec_mode(){
    LcdPrintNumS(0,0,hour/10);
    LcdPrintNumS(0,1,hour%10);
    if(index_set == 1 && blink_flag == 1 && flag_press == 0){
        LcdPrintStringS(0,0," ");
        LcdPrintStringS(0,1," ");
        //blink_flag = 0;
    }
    LcdPrintStringS(0,2,":");
    LcdPrintNumS(0,3,minute/10);
    LcdPrintNumS(0,4,minute%10);
    if(index_set == 2 && blink_flag == 1&& flag_press == 0){
        LcdPrintStringS(0,3," ");
        LcdPrintStringS(0,4," ");
       //blink_flag = 0;
    }
    LcdPrintStringS(0,5,":");
    LcdPrintNumS(0,6,second/10);
    LcdPrintNumS(0,7,second%10);
    if(index_set == 3 && blink_flag == 1&& flag_press == 0){
         LcdPrintStringS(0,6," ");
        LcdPrintStringS(0,7," ");
        //blink_flag = 0;
    }
    LcdPrintStringS(1,0,day_week[day-1]);
    if(index_set == 4 && blink_flag == 1&& flag_press == 0){
        LcdPrintStringS(1,0,"   ");
        //blink_flag = 0;
    }
    LcdPrintStringS(1,3,", ");
    LcdPrintNumS(1,5,date/10);
    LcdPrintNumS(1,6,date%10);
    if(index_set == 5 && blink_flag == 1&& flag_press == 0){
        LcdPrintStringS(1,5,"  ");
        //blink_flag = 0;
    }
    LcdPrintStringS(1,7,"/");
    LcdPrintNumS(1,8,month/10);
    LcdPrintNumS(1,9,month%10);
    if(index_set == 6 && blink_flag == 1&& flag_press == 0){
        LcdPrintStringS(1,8,"  ");
        //blink_flag = 0;
    }
    LcdPrintStringS(1,10,"/");
    LcdPrintNumS(1,11,sub_year/10);
    LcdPrintNumS(1,12,sub_year%10);
    LcdPrintNumS(1,13,year/10);
    LcdPrintNumS(1,14,year%10);
    if(index_set == 7 && blink_flag == 1&& flag_press == 0){
        LcdPrintStringS(1,11,"    ");
        //blink_flag = 0;
    }
}
void Day_Week_Number(){
    int number_of_days;
    int number_of_week;
    int days_of_month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int leap_day = 0;
    if ((((sub_year*100+year) %4  == 0) && ((sub_year*100+year) % 100  != 0)) || ((sub_year*100+year) % 400  == 0)){
        leap_day = 1;
    }
    if (leap_day == 1){
        if (month <= 2){
            number_of_days = days_of_month[(month-1)] + date;
        }
        else{
            number_of_days = days_of_month[(month-1)] + date + leap_day;
        }
    }
    else{
        number_of_days = days_of_month[(month-1)] + date;
    }
    if (day == 1){
        number_of_week = (number_of_days -7 + 10)/7;
    }
    else{
        number_of_week = (number_of_days - day + 10)/7;
    }
    LcdClearS();
    LcdPrintStringS(0,0,"Ngay:");
    LcdPrintNumS(0,6,number_of_days);
    LcdPrintStringS(1,0,"Tuan:");
    LcdPrintNumS(1,6,number_of_week);
    DisplayLcdScreen();   
}
 
void counter_run(){
    counter[3]++;
    if(counter[3] == 100){
        counter[2]++;
        counter[3] = 0;
    }
    if(counter[2] == 60){
        counter[1]++;
        counter[2] = 0;
    }
    if(counter[1] == 60){
        counter[0] = (counter[0]+1)%24;
        counter[1] = 0;
    }
}
void display_counter(){
    LcdPrintStringS(0,0,"Counter Mode");
    if(counter[0] >= 10) LcdPrintNumS(1,0,(int)counter[0]/10);
    LcdPrintNumS(1,1,(int)counter[0]%10);
    LcdPrintStringS(1,2,":");
    LcdPrintNumS(1,3,(int)counter[1]/10);
    LcdPrintNumS(1,4,(int)counter[1]%10);
    LcdPrintStringS(1,5,":");
    LcdPrintNumS(1,6,(int)counter[2]/10);
    LcdPrintNumS(1,7,(int)counter[2]%10);
    LcdPrintStringS(1,8,":");
    LcdPrintNumS(1,9,(int)counter[3]/10);
    LcdPrintNumS(1,10,(int)counter[3]%10);
}
void Alarm(){
    
    if (is_key_down(0)){
        index_set = (index_set+1)%3;
        if (index_set == 0) index_set = 1;
    }
    if (is_key_pressed(6)){
            increase();
            flag_press = 1;
    }
    if (is_key_pressed(4)){
           decrease();
           flag_press = 1;
    }
    
    if (is_key_pressed(5)){
        hour_alarm = hour;
        minute_alarm = minute;
        status = MODE_1;
        alarm_flag = 1;
      
    }
    LcdClearS();
    LcdPrintStringS(0,0,"Moi dat bao thuc");
    Display_alarm();
    DisplayLcdScreen();
    flag_press = 0;
}

void Display_time_big_num(){
    if(format_12h == 1 && format_24h == 0){
        if (hour > 12){
            hour = hour -12;
            isPM_or_AM = 1;
            LcdPrintCharS(0,14,'P');
            LcdPrintCharS(0,15,'M');
        }
        else if (hour == 12){
            isPM_or_AM = 1;
            LcdPrintCharS(0,14,'P');
            LcdPrintCharS(0,15,'M');
        }
        else{
            if (hour ==0 ) hour = 12;
            isPM_or_AM = 0;
            LcdPrintCharS(0,14,'A');
            LcdPrintCharS(0,15,'M'); 
        }  
        Display_big_number(0,0,hour/10);
        Display_big_number(0,3,hour%10);
        LcdPrintCharS(0,6,7);
        LcdPrintCharS(1,6,7);
        Display_big_number(0,7,minute/10);
        Display_big_number(0,10,minute%10);  
    }
    else{
        Display_big_number(0,1,hour/10);
        Display_big_number(0,4,hour%10);
        LcdPrintCharS(0,7,7);
        LcdPrintCharS(1,7,7);
        Display_big_number(0,8,minute/10);
        Display_big_number(0,11,minute%10);
        LcdPrintCharS(0,14,' ');
        LcdPrintCharS(0,15,' '); 
    }
    DisplayLcdScreen();
}

void Display_animation_menu(){
    if (is_key_down(5)){
        index_animation_set = index_animation;
    }
    if (flag_animation_menu == 1){
        LcdClearS();
        LcdPrintStringS(0,1,"ANIMATION MODE");
        DisplayLcdScreen();
        delay_ms(1000);
        flag_animation_menu = 0;
    }
    if (index_animation_set == -1){
      int n;
      lcd_write_cmd(64);
      for (n = 0; n<=7; n++) lcd_write_data(arrow[n]); 
        LcdClearS();
        LcdPrintStringS(0,0,"Man Walking");
        LcdPrintStringS(1,0,"Wave");
        LcdPrintCharS(index_animation,15,0);
        DisplayLcdScreen();
    }
    LcdClearS();
    if (is_key_down(6)){
        index_animation++;
        if (index_animation > animation_menu_size -1){
            index_animation = animation_menu_size -1;
        }
    }
    if (is_key_down(4)){
        index_animation--;
        if (index_animation < 0){
            index_animation = 0;
        }
    }
    switch(index_animation_set){
        case 0: 
            Display_animation();
            break;
        case 1:
            wave_animation();
            break;
        default:
            break;
    }
}


void focus_run(){
    second  = read_ds1307(ADDRESS_SECOND);
    if(second_focus != second){
        second_focus = second;
        if(focus[0] > 0){
            focus[1] = (focus[1]-1+60)%60;
            if(focus[1] == 59){
                focus[0]--;
            }
        }
        else{
            if(focus[1] > 0) focus[1]--;
        }
    }
}

void Display_focus(){
    LcdClearS();
    LcdPrintStringS(0,0,"Focus Mode");
    if(focus[0] >= 10) LcdPrintNumS(1,0,(int)focus[0]/10);
    LcdPrintNumS(1,1,(int)focus[0]%10);
    LcdPrintStringS(1,2,":");
    LcdPrintNumS(1,3,(int)focus[1]/10);
    LcdPrintNumS(1,4,(int)focus[1]%10);
    if(index_focus == 1 && blink_flag == 1){
        LcdPrintStringS(1,0," ");
        LcdPrintStringS(1,1," ");
        //blink_flag = 0;
    }
    if(index_focus == 2 && blink_flag == 1){
        LcdPrintStringS(1,3," ");
        LcdPrintStringS(1,4," ");
        //blink_flag = 0;
    }
    DisplayLcdScreen();  
}

