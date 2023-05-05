#include "game_LCD.h"
#include "custom_character.h"
#include <stdlib.h>
 char world[] = {
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'S', 'C', 'O', 'R', 'E', ':', ' ', ' ', ' ',
    ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
 };
 int score = 0;
 int index3;
 int allow_to_jump = 0;
int status_game_mode = READY;
 void create_character(){
     int n;
     lcd_write_cmd(64);
     for (n = 0; n<=7; n++) lcd_write_data(dino_l[n]);        //0  
     lcd_write_cmd(72);
     for (n = 0; n<=7; n++) lcd_write_data(dino_r[n]);  // 1
     lcd_write_cmd(80);
     for (n = 0; n<=7; n++) lcd_write_data(cactus_small[n]); // 2
     lcd_write_cmd(88); 
     for (n = 0; n<=7; n++) lcd_write_data(cactus_big[n]); // 3
     lcd_write_cmd(96); 
     for (n = 0; n<=7; n++) lcd_write_data(sad_face[n]); // 4
     lcd_write_cmd(104); 
     for (n = 0; n<=7; n++) lcd_write_data(happy_face[n]); // 5
 }

 int GetRandom(int min,int max){
   return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
 int scroll_world(){
     
     char prev;
     char random_obj  = GetRandom(2,35);
     delay_ms(150);
     if (random_obj < 4){
         world[31] = random_obj;
     }
     else world[31] = ' ';
     for (index3 = 16; index3 < 32; index3++) {
        if (world[index3] == 2 || world[index3] == 3) {
            if (index3 < 31){
                prev = world[index3+1];
            }
            else prev = ' ';
        if (world[index3 - 1] < 2){
            return 1;
        }
        world[index3 - 1] = world[index3];
        world[index3] = prev;
      }
    }
    world[15] = ' ';
    if (world[16] < 2) world[16] = ' ';
    return 0;  
 }
 int game_over;
 int index1;
 int index2;
 int row;
  void clear_game_mode(){
      int clear_index;
      status_game_mode = READY;
     score = 0;
     game_over = 0;
     index1 = 0;
     index2 = 0;
     row = 0;
     for(clear_index = 0; clear_index <= 6; clear_index++ ){
         world[clear_index] = ' ';
     }
     for(clear_index = 13; clear_index <= 16; clear_index++){
         world[clear_index] = ' ';
     }
     world[17] = 0;
     for(clear_index = 18; clear_index <= 31; clear_index++){
         world[clear_index] = ' ';
     }
 }
 void update_world(){
     game_over = scroll_world();
     score++;
     LcdPrintNumS(0,13,score/100);
     LcdPrintNumS(0,14,(score%100)/10);
     LcdPrintNumS(0,15,(score%100)%10);
     row = 0;
     for (index1 = 0; index1 < 32; index1++) {
       if (world[index1] < 2) world[index1] ^= 1;
       if (index1 == 16) row = 1;
       if (index1 < 13 || index1 > 15){
           LcdPrintCharS(row,index1,world[index1]);
       }
    }
    if (game_over == 1){
         status_game_mode = GAME_OVER;
         //break;
    }
     if (score == 999){
         status_game_mode = WIN;
         //break;
     }
     DisplayLcdScreen();
 }
 void Display_game(){
     int n;
     switch(status_game_mode){
         case READY:
             LcdClearS();
             LcdPrintStringS(0,1,"ARE YOU READY?");
             LcdPrintStringS(1,1,"PRESS TO PLAY");
            lcd_write_cmd(112);
            for (n = 0; n<=7; n++) lcd_write_data(play[n]);  
            LcdPrintCharS(1,15,6);
             if (is_key_down(5)){
                 status_game_mode = PLAY;
                 create_character();
                 LcdPrintCharS(1,1,0);
                 LcdPrintCharS(0,1,' ');
                 DisplayLcdScreen();
                 delay_ms(150);
                 break;
             }
             break;
         case PLAY:
             allow_to_jump = 1 - allow_to_jump;
             if (is_key_pressed_for_game(5)&& allow_to_jump == 1){
                 LcdPrintCharS(1,1,' ');
                 LcdPrintCharS(0,1,0);
            
                 world[1] = 0;
                 world[17] = ' ';
                 for (index2 = 0; index2 < 4; index2++) update_world();
                 world[1] = ' ';
                 world[17] = 0;
                 LcdPrintCharS(1,1,0);
                 LcdPrintCharS(0,1,' ');
                 DisplayLcdScreen();
             }
             update_world();
             break;
         case GAME_OVER:
            if (is_key_down(5)){
                 status_game_mode = READY;
                 clear_game_mode();
                 break;
             }
             LcdPrintStringS(1,4,"GAME OVER!");
             LcdPrintCharS(1,14,4);
             LcdPrintCharS(1,15,' ');
             
             break;
         case WIN:
            LcdClearS();
            if (is_key_down(5)){
                 status_game_mode = READY;
                 clear_game_mode();
                 break;
             }
            LcdPrintStringS(0,3,"YOU WIN!");
            LcdPrintCharS(0,12,5);
            LcdPrintCharS(1,0,0);
            LcdPrintCharS(1,1,' ');
            LcdPrintCharS(1,2,2);
            LcdPrintCharS(1,3,2);
            LcdPrintCharS(1,4,2);
            LcdPrintCharS(1,5,3);
            LcdPrintCharS(1,6,3);
            LcdPrintCharS(1,7,3);
            LcdPrintCharS(1,8,3);
            LcdPrintCharS(1,9,3);
            LcdPrintCharS(1,10,3);
            LcdPrintCharS(1,11,2);
            LcdPrintCharS(1,12,2);
            LcdPrintCharS(1,13,2);
            LcdPrintCharS(1,14,' ');
            LcdPrintCharS(1,15,1);
            DisplayLcdScreen();
            break;
           
                    
     }
 }