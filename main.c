/*
 ============================================================================
 Name        : main.c
 Author      : samy ibrahem
 Description : Integrate the Keypad and LCD drivers to make a Calculator.
 Date        : 14/2/2022
 ============================================================================
 */
#include "lcd.h"
#include "keypad.h"
#include "gpio.h"
#include <util/delay.h>/* For the delay functions */
int main (void){
LCD_init();
GPIO_setupPinDirection(PORTD_ID,PIN4_ID,PIN_OUTPUT);
GPIO_setupPinDirection(PORTD_ID,PIN5_ID,PIN_OUTPUT);

uint8 key=0;/* variable to hold the pressed key value */
uint8 num=0;/* variable to hold the first number value*/
uint8 num1=1;/* variable to hold the second number value*/
uint8 op=0;/* variable to hold the operation*/
	    while(1)
	    {
	    	LCD_displayString("Samy door");
	    	LCD_moveCursor(2,0);
	    	LCD_displayString("open door :+");
	    	LCD_moveCursor(3,0);
	    	LCD_displayString("change pass :-");
	    	key=KEYPAD_getPressedKey();
	    	_delay_ms(300);
	    	op=key;
	    	switch (op){
	    	case '+':
	    		LCD_clearScreen();
	    		LCD_displayString("enter password:");
	    		LCD_moveCursor(2,0);
		    	key=KEYPAD_getPressedKey();
	    		while((key>=0) && (key<=9)){
	    			LCD_displayCharacter('*');
	    			num=num*10+key;
	    			_delay_ms(300);
	    			key=KEYPAD_getPressedKey();
	    		}
	    		if(num==num1){
	    			GPIO_writePin(PORTD_ID,PIN4_ID,LOGIC_LOW);
	    			GPIO_writePin(PORTD_ID,PIN4_ID,LOGIC_HIGH);
	    			_delay_ms(1000);
	    			GPIO_writePin(PORTD_ID,PIN4_ID,LOGIC_LOW);
	    		    GPIO_writePin(PORTD_ID,PIN4_ID,LOGIC_LOW);
	    		    LCD_clearScreen();
	    		    LCD_displayString("Welcome");
	    		    _delay_ms(2000);
	    		}
	    		else{
	    			LCD_moveCursor(4,0);
	    			LCD_displayString("Wrong password");
	    		}
	    		break;
	    	case '-':
	    		LCD_clearScreen();
	         	LCD_displayString("enter password:");
	    	    LCD_moveCursor(2,0);
	    	    key=KEYPAD_getPressedKey();
	    	    while((key>=0) && (key<=9)){
	    	  	LCD_displayCharacter('*');
	    	    num=num*10+key;
	    	   	_delay_ms(300);
	    	  	key=KEYPAD_getPressedKey();
	    	    	    		}
	    	    if(num==num1){
	    	    	LCD_clearScreen();
	    	    	num1=0;
	    	    	LCD_displayString("NEW password:");
	    	    	LCD_moveCursor(2,0);
	    	    	key=KEYPAD_getPressedKey();
	    	    	while((key>=0) && (key<=9)){
	    	    		LCD_intgerToString(key);
	    	    		num1=num1*10+key;
	    	    		 _delay_ms(300);
	    	    		key=KEYPAD_getPressedKey();
	    	    		    		}
	    	    	LCD_moveCursor(3,0);
	    	    	LCD_displayString("Password set");
	    	    	_delay_ms(1000);
	    	    	    		}
	    	    else{
	    	    	    			LCD_moveCursor(4,0);
	    	    	    			LCD_displayString("Wrong password");
	    	    	    		}
	    	    break;
	    	default :
	    		LCD_clearScreen();
	    			         	LCD_displayString("ERROR");
	    			         	_delay_ms(1000);
	    			         	break;
	    	}
	    	LCD_clearScreen();
key=0;
num=0;
op=0;

	    }

}

