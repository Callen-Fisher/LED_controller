#define STM32F051

#include <stdint.h>
#include "stm32f0xx.h"
#include "lcd_stm32f0.h"
#include "LED.h"
#include "PB.h"

#define red 0
#define white 2
#define blue 1

#define mode_1 0
#define mode_2 1
#define mode_3 2
#define mode_4 3

uint8_t mode=0;
uint32_t i = 0;

void main(void);
uint8_t get_mode(uint8_t);
void strobe_delay(void);

extern void lcd_init (void);


void main(void) {
  int i =0;
  lcd_init(); // set up LCD lines and send initialisation commands
  lcd_command(LCD_CLEAR_DISPLAY);
  lcd_string("LED desk lights");
  lcd_command(LCD_GOTO_LINE_2); // go to lower line
  lcd_string("V1.0");


  init_LEDs();
  init_push_buttons();
  // set LEDs to outputs
  for(;;)
  {

	  mode=get_mode(mode);
	  switch(mode)
	  {
	  case mode_1:
		  light_on(white);
		  light_off(red);
		  light_off(blue);
		  break;
	  case mode_2:
		  light_on(white);
		  light_on(red);
		  light_on(blue);
		  break;
	  case mode_3:
		  light_on(white);
		  light_on(red);
		  light_on(blue);
		  i=0;
		  strobe_delay();
		  light_off(white);
		  light_off(red);
		  light_off(blue);
		  strobe_delay();
		  break;
	  case mode_4:
		  break;
	  default:
		  break;
	  }






  }
}

uint8_t get_mode(uint8_t current_mode)
{
	uint8_t new_mode=current_mode;
	if(get_button_state(mode_1)==1)
	{
		new_mode=mode_1;
	}
	else if(get_button_state(mode_2)==1)
	{
		new_mode=mode_2;
	}
	else if(get_button_state(mode_3)==1)
	{
		new_mode=mode_3;
	}
	else if(get_button_state(mode_4)==1)
	{
		new_mode=mode_4;
	}

	return new_mode;
}
void strobe_delay()
{
	int i=0;
	for(; i < 65535; i++);
}
