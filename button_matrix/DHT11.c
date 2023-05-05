#include "DHT11.h"
#include "clock.h"
char Check_bit;
void delay_us(int value)
{
   	int i,j;
	for(i = 0; i < value; i++){
    for(j = 0; j < 1; j++);
    }
}
void dht11_init(){
    DHT11_Data_Pin_Direction= 0; //Configure RD0 as output
    DHT11_Data_Pin = 0; //RD0 sends 0 to the sensor
    delay_ms(18);
    DHT11_Data_Pin = 1; //RD0 sends 1 to the sensor
    delay_us(5);
    DHT11_Data_Pin_Direction = 1; //Configure RD0 as input
}
void find_response(){
    Check_bit = 0;
    delay_us(7);
    if (DHT11_Data_Pin == 0){
        delay_us(13);
        if (DHT11_Data_Pin == 1){
         Check_bit = 1;
    }          
    delay_us(8);}
}
char read_dht11(){
    char data, for_count;
    for(for_count = 0; for_count < 8; for_count++){
        while(!DHT11_Data_Pin);
            delay_us(30);
            if(DHT11_Data_Pin == 0){
                data&= ~(1<<(7 - for_count)); //Clear bit (7-b)
            }
            else{
                data|= (1 << (7 - for_count)); //Set bit (7-b)
                while(DHT11_Data_Pin);
            }
    }
    return data;
}
 /*
void DHT11_Start (void)
{
	DHT11_Data_Pin_Direction = 0;    // set the pin as output
	DHT11_Data_Pin  = 0;              // set the pin low
	delay_ms(18);            // wait for 18ms
	DHT11_Data_Pin_Direction = 1;    // set the PIN as input
}

void DHT11_Check_Response (void)  
{
	while (DHT11_Data_Pin);          // wait for pin to go low
    while (!DHT11_Data_Pin);         // wait for the pin to go HIGH
	while (DHT11_Data_Pin);          // wait for the pin to go low
}

char read_data (void)
{
	char index5,index6;
	for (index6 = 0;index6 < 8; index6++)
	{
		while (DHT11_Data_Pin == 0);           // wait for the pin to go high
		delay_us(7);                  // wait for 40 us
		if (DHT11_Data_Pin == 0)               // if the pin is low 
		{
			index5 &= ~(index5<<(7-index6));              // write 0
		}
		else index5|= (1<<(7-index6));              // if the pin is high, write 1
		while (DHT11_Data_Pin);                // wait for the pin to go low
	}
	return index5;
}*/