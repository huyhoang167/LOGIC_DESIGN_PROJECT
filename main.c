#include "main.h"
#include "i2c.h"
#include "button_matrix/global.h"
#include "button_matrix/clock.h"

#define     LED     PORTD
#define     ON      1
#define     OFF     0

unsigned char arrayMapOfOutput [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char statusOutput[8] = {0,0,0,0,0,0,0,0};
int blink_count = 3;
int buzzer_count = 5;
void init_system(void);
void delay_ms(int value);
void OpenOutput(int index);
void CloseOutput(int index);
void TestOutput(void);
void ReverseOutput(int index);

//Bai tap chong rung nut nhan
char numberOfPushButton = 0;
unsigned char isButtonUp();
unsigned char isButtonDown();
void BaiTap_ChongRung();
void Test_KeyMatrix();




void main(void)
{   
	init_system();
    status = INIT ;
//    Set_Time();
	while (1)
	{   
        if (flag_timer0 == 1){
            SetTimer0_ms(10);
            if(turn_counter){
                counter_run(); 
            }
        } 
        if (flag_timer3 == 1){
            SetTimer3_ms(50);
            if (alarm_flag == 0){
                scan_key_matrix();
            }
            else{
                scan_key_matrix1();
                PORTCbits.RC2 = 0;
            }
            blink_flag = 1 - blink_flag;
            blink_count--;
            buzzer_count--;
       }
       if (blink_count <= 0){
           flag_alarm_blink = 1;
           if (blink_count == -3){
               blink_count = 3;
           }
       }
       if (buzzer_count <= 0){
           buzzer_flag = 1;   
           if (buzzer_count == -5){
               buzzer_count = 5;
           }
       }
     
        fsm();
    }
  


}
void delay_ms(int value)
{
	int i,j;
	for(i = 0; i < value; i++)
		for(j = 0; j < 160; j++);
}

void init_system(void)
{
    TRISB = 0x00;		//setup PORTB is output
    TRISD = 0x00;
    
    init_lcd();
    LcdClearS();
    LED = 0x00;
    init_interrupt();
    delay_ms(1000);
    init_timer0(4695);  //dinh thoi 1ms
    init_timer1(9390);  //dinh thoi 2ms
    init_timer3(46950); //dinh thoi 10ms
    SetTimer0_ms(10);
    SetTimer1_ms(10);
    SetTimer3_ms(50);   //Chu ky thuc hien viec xu ly input,proccess,output
    init_key_matrix();
    init_i2c();
    TRISCbits.TRISC2 = 0;
}

void OpenOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED | arrayMapOfOutput[index];
	}

}

void CloseOutput(int index)
{
	if (index >= 0 && index <= 7)
	{
		LED = LED & ~arrayMapOfOutput[index];
	}
}

void ReverseOutput(int index)
{
    if (statusOutput[index]  == ON)
    {
        CloseOutput(index);
        statusOutput[index] = OFF;
    }
    else
    {
        OpenOutput(index);
        statusOutput[index] = ON;
    }
}

void TestOutput(void)
{
	int i;
	for (i = 0; i <= 7 ; i++ )
	{
		OpenOutput(i);
		delay_ms(500);
		CloseOutput(i);
		delay_ms(500);
	}
}

unsigned char isButtonUp()
{
    if (key_code[0] == 1 || (key_code[0] >= 20 && key_code[0]%2 == 1))
        return 1;
    else
        return 0;
}
unsigned char isButtonDown()
{
    if (key_code[1] == 1)
        return 1;
    else
        return 0;
}

void BaiTap_ChongRung()
{
    if (isButtonUp() == 1)
        numberOfPushButton ++;
    if (isButtonDown())
        numberOfPushButton --;
 
    LcdPrintStringS(0,0,"    ");
    LcdPrintNumS(0,0,numberOfPushButton);
}

void Test_KeyMatrix()
{
    int i;
    for (i = 0; i < 16; i++)
    {
        if(key_code[i] != 0)
            LcdPrintStringS(1,i,"_");
        else
            LcdPrintStringS(1,i," ");
    }
}