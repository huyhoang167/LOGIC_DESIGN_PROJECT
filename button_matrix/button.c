#include "button.h"

unsigned int key_code[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char arrayMaskOutputOfKey [4] = {0x10,0x20,0x40,0x80};
unsigned char arrayMaskInputOfKey [4] = {0x01,0x02,0x04,0x08};
unsigned char arrayMaskInputOfButton [8] = {0x01,0x02,0x04,0x08,
                                            0x10,0x20,0x40,0x80};
unsigned char arrayMaskOutputOfKey1 [4] = {0x14,0x24,0x44,0x84};
void init_key_matrix()
{
//    khoi tao nut nhan truc tiep
//	TRIS_BUTTON = 0xff;
//	PORT_BUTTON = 0xff;
//    //khoi tao nut nhan cho ma tran phim
   TRIS_BUTTON = 0x0f;
   PORT_BUTTON = 0xff;
}

void scan_key_button()
{
	int i,j;
    for(i=0;i<8;i++)
    {
        if((PORT_BUTTON & arrayMaskInputOfButton[i]) == 0)
            key_code[i] = key_code[i] + 1;
        else
            key_code[i] = 0;

    }
}
void scan_key_matrix()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)
	{
		PORT_BUTTON = ~arrayMaskOutputOfKey[i];
		for(j=0;j<MAX_COL;j++)
		{ 
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)
				key_code[i*MAX_ROW+j] = key_code[i*MAX_ROW+j] + 1;
			else
				key_code[i*MAX_ROW+j] = 0;
		}
	}
}
void scan_key_matrix1()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)
	{
		PORT_BUTTON = ~arrayMaskOutputOfKey1[i];
		for(j=0;j<MAX_COL;j++)
		{
            if (j == 2) continue;
			if((PORT_BUTTON & arrayMaskInputOfKey[j]) == 0)
				key_code[i*MAX_ROW+j] = key_code[i*MAX_ROW+j] + 1;
			else
				key_code[i*MAX_ROW+j] = 0;
		}
	}
}
int is_key_pressed(int index){
    if(key_code[index] == 1 || (key_code[index] >= 10 && key_code[index]%2 == 1)){
        key_code[index]++;
        return 1;
    }
    return 0;
}

int is_key_down(int index){
    if(key_code[index] == 1){
        key_code[index]++;
        return 1;
    }
    return 0;
}
int is_key_pressed_for_game(int index){
    if(key_code[index] == 1 || key_code[index] > 0){
        key_code[index]++;
        return 1;
    }
    return 0;
}