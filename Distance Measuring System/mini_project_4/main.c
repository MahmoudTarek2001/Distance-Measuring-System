/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: main project file for the AVR microcontroller
 *
 * Author: Mahmoud Tarek
 *
 *******************************************************************************/
#include "lcd.h"/*To initialize and use the lcd functions*/
#include "ultrasonic.h"/*To initialize and use the ultrasonic sensor*/


int main(){

	uint16 distance=0;
	/*initialize the lcd*/
	LCD_init();
	/*initialize the ultrasonic sensor*/
	Ultrasonic_init();
	LCD_displayString("Distance=     cm");
	/*main while loop*/
	while(1){
		/*function to read the distance from the ultrasonic sensor and store it in variable*/
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else if((distance >= 10)||(distance < 100))
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayCharacter('  ');
		}
	}
}
