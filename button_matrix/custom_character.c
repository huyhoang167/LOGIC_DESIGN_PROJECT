#include "custom_character.h"
#include "animation_data.h"
#include "animation_data1.h"
#include "animation_data2.h"
#include "animation_data3.h"
#include "button.h"
#include "global.h"
char CUL[] = {7,15,31,31,31,31,31,31};
char UP[] = {31,31,31,0,0,0,0,0};
char CUR[] = {28,30,31,31,31,31,31,31};
char CDL[] = {31,31,31,31,31,31,15,7};
char DOWN[] = {0,0,0,0,0,31,31,31};
char CDR[] = {31,31,31,31,31,31,30,28};
char EIGHT_UP[] = {31,31,31,0,0,0,31,31};
char dot[] = {0,0,14,14,14,14,0,0};


void custom_char_num()
{  
        int m;
        lcd_write_cmd(64);
        for (m = 0; m<=7; m++) lcd_write_data(CUL[m]);        //0  
        lcd_write_cmd(72);
        for (m = 0; m<=7; m++) lcd_write_data(UP[m]);  // 1
        lcd_write_cmd(80);
        for (m = 0; m<=7; m++) lcd_write_data(CUR[m]); // 2
        lcd_write_cmd(88); 
        for (m = 0; m<=7; m++) lcd_write_data(CDL[m]); // 3
        lcd_write_cmd(96);
        for (m = 0; m<=7; m++) lcd_write_data(DOWN[m]); // 4
        lcd_write_cmd(104);
        for (m = 0; m<=7; m++) lcd_write_data(CDR[m]); // 5
        lcd_write_cmd(112);
        for (m = 0; m<=7; m++) lcd_write_data(EIGHT_UP[m]); // 6
        lcd_write_cmd(120);
        for (m = 0; m<=7; m++) lcd_write_data(dot[m]); 
}
void custom_char_animation(char data0[],char data1[],char data2[],char data3[],char data4[],char data5[])
{      
        int n;
        lcd_write_cmd(64);
        for (n = 0; n<=7; n++) lcd_write_data(data0[n]);        //0  
        lcd_write_cmd(72);
        for (n = 0; n<=7; n++) lcd_write_data(data1[n]);  // 1
        lcd_write_cmd(80);
        for (n = 0; n<=7; n++) lcd_write_data(data2[n]); // 2
        lcd_write_cmd(88); 
        for (n = 0; n<=7; n++) lcd_write_data(data3[n]); // 3
        lcd_write_cmd(96);
        for (n = 0; n<=7; n++) lcd_write_data(data4[n]); // 4
        lcd_write_cmd(104);
        for (n = 0; n<=7; n++) lcd_write_data(data5[n]); // 5
}
void Display_0(char row, char column)
{
        LcdPrintCharS(row,column,0);
        LcdPrintCharS(row,column+1,1);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column,3);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_1(char row, char column)
{
        LcdPrintCharS(row,column,1);
        LcdPrintCharS(row,column+1,2);
        LcdPrintCharS(row+1,column,4);
        LcdPrintCharS(row+1,column+1,255);
        LcdPrintCharS(row+1,column+2,4);
}
void Display_2(char row, char column)
{
        LcdPrintCharS(row,column,6);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column,3);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,4);
}
void Display_3(char row, char column)
{
        LcdPrintCharS(row,column,6);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column,4);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_4(char row, char column)
{
        LcdPrintCharS(row,column,3);
        LcdPrintCharS(row,column+1,4);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_5(char row, char column)
{
        LcdPrintCharS(row,column,3);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,6);
        LcdPrintCharS(row+1,column,4);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_6(char row, char column)
{
        LcdPrintCharS(row,column,0);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,6);
        LcdPrintCharS(row+1,column,3);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_7(char row, char column)
{
        LcdPrintCharS(row,column,1);
        LcdPrintCharS(row,column+1,1);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_8(char row, char column)
{
        LcdPrintCharS(row,column,0);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column,3);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void Display_9(char row, char column)
{
        LcdPrintCharS(row,column,0);
        LcdPrintCharS(row,column+1,6);
        LcdPrintCharS(row,column+2,2);
        LcdPrintCharS(row+1,column+1,4);
        LcdPrintCharS(row+1,column+2,5);
}
void LCD_Erase(char row, char column)
{
  LcdPrintCharS(row,column,' ');
  LcdPrintCharS(row,column + 1,' ');
  LcdPrintCharS(row,column + 2,' ');
  LcdPrintCharS(row + 1,column,' ');
  LcdPrintCharS(row + 1,column + 1,' ');
  LcdPrintCharS(row + 1,column + 2,' ');
}
void Animation_to_right(char row,char column){
        LcdPrintCharS(row,column,1);
        LcdPrintCharS(row+1,column,0);
        LcdPrintCharS(row+1,column+1,2);
        LcdPrintCharS(row,column+1,3);
        LcdPrintCharS(row+1,column+2,4);
        LcdPrintCharS(row,column+2,5);
}
void Animation_to_left(char row,char column){
        LcdPrintCharS(row,column-2,1);
        LcdPrintCharS(row+1,column-2,0);
        LcdPrintCharS(row+1,column-1,2);
        LcdPrintCharS(row,column-1,3);
        LcdPrintCharS(row+1,column,4);
        LcdPrintCharS(row,column,5);
}
void Display_big_number(char row, char column, char number){
    switch(number){
        case 0: 
            Display_0(row,column);
            break;
        case 1: 
            Display_1(row,column);
            break;
        case 2: 
            Display_2(row,column);
            break;
        case 3: 
            Display_3(row,column);
            break;
        case 4: 
            Display_4(row,column);
            break;
        case 5: 
            Display_5(row,column);
            break;
        case 6: 
            Display_6(row,column);
            break;
        case 7: 
            Display_7(row,column);
            break;     
        case 8: 
            Display_8(row,column);
            break;
        case 9: 
            Display_9(row,column);
            break;
        default: 
            break;
    }
}
int count5 = 0;
int count6 = 0;
int flag_animation = 1;
void Display_animation(){
    LcdClearS();
    if (flag_animation == 1){
        custom_char_animation(stepA1,stepA2,stepA3,stepA4,stepA5,stepA6);
        Animation_to_right(0,0);  
        LcdPrintStringS(0,6,"ANIMATION");
        LcdPrintStringS(1,5,"MAN WALKING");
        DisplayLcdScreen();
        delay_ms(1000);
        LcdClearS();
        flag_animation = 0;
    }
    if (is_key_down(13)){
        status = MODE_2;
        LcdClearS();
        flag_animation = 1;
        count5 = 0;
        count6 = 0;    
    }
    else{
        if(count5 < 11){ 
            custom_char_animation(stepB1,stepB2,stepB3,stepB4,stepB5,stepB6);
            Animation_to_right(0,count5+1);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepC1,stepC2,stepC3,stepC4,stepC5,stepC6);
            Animation_to_right(0,count5+2);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepB1,stepB2,stepB3,stepB4,stepB5,stepB6);
            Animation_to_right(0,count5+3);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepD1,stepD2,stepD3,stepD4,stepD5,stepD6);
            Animation_to_right(0,count5+4);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();     
        }
        if (count5 == 12){
            custom_char_animation(slipA1,slipA2,slipA3,slipA4,slipA5,slipA6);
            Animation_to_right(0,13);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();  
            custom_char_animation(slipB1,slipB2,slipB3,slipB4,slipB5,slipB6);
            Animation_to_right(0,13);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();  
            custom_char_animation(slipC1,slipC2,slipC3,slipC4,slipC5,slipC6);
            Animation_to_right(0,13);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();  
            count6 = 16;
        }
        if(count6 > 4 && count5 >= 11){
            custom_char_animation(stepE1,stepE2,stepE3,stepE4,stepE5,stepE6);
            Animation_to_left(0,count6-1);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepF1,stepF2,stepF3,stepF4,stepF5,stepF6);
            Animation_to_left(0,count6-2);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepE1,stepE2,stepE3,stepE4,stepE5,stepE6);
            Animation_to_left(0,count6-3);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(stepG1,stepG2,stepG3,stepG4,stepG5,stepG6);
            Animation_to_left(0,count6-4);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();  
        }
        if (count6 <=4 && count5 >= 11){
            count6 = 0;
            custom_char_animation(slipD1,slipD2,slipD3,slipD4,slipD5,slipD6);
            Animation_to_right(0,count6+1);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(slipE1,slipE2,slipE3,slipE4,slipE5,slipE6);
            Animation_to_right(0,count6+1);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            custom_char_animation(slipF1,slipF2,slipF3,slipF4,slipF5,slipF6);
            Animation_to_right(0,count6+1);
            DisplayLcdScreen();
            delay_ms(200);
            if (is_key_down(13)){
                status = MODE_2;
                LcdClearS();
                flag_animation = 1;
                count5 = 0;
                count6 = 0;    
            }
            LcdClearS();
            count5= 0;
            count6= 0;
        }
        else{
        count5= count5+4;
        count6= count6-4;
        }
    }
}
int wave_i=0;
int wave_j=0;
int randomnum;
int wave_k=0;
void test(){
  if (wave_i ==8)
   {
        wave_j= 4;
        wave_k=4;
   }
  if (wave_i ==7)
  {
    wave_j=3;
    wave_k=4;
  }
  if (wave_i ==6)
  {
    wave_j=2;
    wave_k=4;
  }
  if (wave_i ==5)
  {
    wave_j=1;
    wave_k=4;
  }
  if (wave_i ==4)
  {
    wave_j=0;
    wave_k=4;
  }
  if (wave_i ==3)
  {
    wave_j=0;
    wave_k=3;
  }
  if (wave_i ==2)
  {
    wave_j=0;
    wave_k=2;
  }
  if (wave_i ==1)
  {
    wave_j=0;
    wave_k=1;
  }
   if (wave_i ==0)
  {
    wave_j=0;
    wave_k=0;
  }
}
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
void wave_animation(){
    int n;
    LcdClearS();
    if (flag_animation == 1){
        LcdPrintStringS(0,6,"WAVE");
        LcdPrintStringS(1,4,"ANIMATION");
        DisplayLcdScreen();
        delay_ms(1000);
        LcdClearS();
        flag_animation = 0;
    }
    if (key_code[14] > 0){
        status = MODE_2;
        key_code[14] = 0;
        LcdClearS();
        flag_animation = 1;
        wave_i = 0;
        wave_j = 0;   
        wave_k = 0;
    }
    lcd_write_cmd(64);
    for (n = 0; n<=7; n++) lcd_write_data(customChar5[n]);        //0  
    lcd_write_cmd(72);
    for (n = 0; n<=7; n++) lcd_write_data(customChar4[n]);  // 1
    lcd_write_cmd(80);
    for (n = 0; n<=7; n++) lcd_write_data(customChar3[n]); // 2
    lcd_write_cmd(88); 
    for (n = 0; n<=7; n++) lcd_write_data(customChar2[n]); // 3
    lcd_write_cmd(96);
    for (n = 0; n<=7; n++) lcd_write_data(customChar1[n]); // 4
    if (wave_i <= 0){
        randomnum = random(6,9);
        wave_i=randomnum;
    }
    if (wave_i>0){
        int z = wave_i;
        test();
        LcdPrintCharS(0,7,wave_j);
        LcdPrintCharS(1,7,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,8,wave_j);
        LcdPrintCharS(1,8,wave_k);
        LcdPrintCharS(0,6,wave_j);
        LcdPrintCharS(1,6,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,9,wave_j);
        LcdPrintCharS(1,9,wave_k);
        LcdPrintCharS(0,5,wave_j);
        LcdPrintCharS(1,5,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,10,wave_j);
        LcdPrintCharS(1,10,wave_k);
        LcdPrintCharS(0,4,wave_j);
        LcdPrintCharS(1,4,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,11,wave_j);
        LcdPrintCharS(1,11,wave_k);
        LcdPrintCharS(0,3,wave_j);
        LcdPrintCharS(1,3,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,12,wave_j);
        LcdPrintCharS(1,12,wave_k);
        LcdPrintCharS(0,2,wave_j);
        LcdPrintCharS(1,2,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,13,wave_j);
        LcdPrintCharS(1,13,wave_k);
        LcdPrintCharS(0,1,wave_j);
        LcdPrintCharS(1,1,wave_k);
        wave_i--;
        test();
        LcdPrintCharS(0,14,wave_j);
        LcdPrintCharS(1,14,wave_k);
        LcdPrintCharS(0,0,wave_j);
        LcdPrintCharS(1,0,wave_k);
        DisplayLcdScreen();
        LcdClearS();
        wave_i=z;
        wave_i = wave_i - 3;
 }
    }
