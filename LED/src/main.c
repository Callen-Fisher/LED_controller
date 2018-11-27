#define STM32F051

#include <stdint.h>
#include "stm32f0xx.h"
#include "lcd_stm32f0.h"
#include "LED.h"

void main(void);


extern void lcd_init (void);


void main(void) {
  int i =0;
  lcd_init(); // set up LCD lines and send initialisation commands
  lcd_command(LCD_CLEAR_DISPLAY);
  lcd_string("LED desk lights");
  lcd_command(LCD_GOTO_LINE_2); // go to lower line
  lcd_string("V1.0");


  init_LEDs();
  // set LEDs to outputs
  int counter=1;
  for(;;) {
    for(i=0; i < 65535; i++);
    light_toggle(counter);
    for(i=0; i < 65535; i++);
    light_toggle(counter);
    counter=counter+1;

    if(counter>8)
    	counter=1;
  }
}


