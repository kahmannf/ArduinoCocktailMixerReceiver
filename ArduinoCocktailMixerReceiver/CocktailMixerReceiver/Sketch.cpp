/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <avr/delay.h>

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

int current_beverage;

int dataAmount;

int slot = -1;
int state = -1;

void toggle_pin(int, int);

void setup() 
{
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	PORTD = 0b11111100;

	PORTB = 0b00111111;
	
	Serial.begin(9600);

	current_beverage = -1;
}

//sleep time in 1/10 sec
void toggle_pin(int slot, int state)
{
	/* pins are match like this: 
		D0: blocked for serial data (receive);
		D1: blocked for serial data (transmit);
		
		B0: 0
		B1: 1
		B2: 2
		B3: 3
		B4: 4
		B5: 5 
		 
		D2: 10
		D3: 11
		D4: 12
		D5: 13
		D6: 14
		D7: 15

	 */

	 if(slot < 6) //B-Register
	 {
		if(state == 0)
		{
			PORTB |= (1<<(slot));
		}
		else
		{
			PORTB &= ~(1<<(slot));
		}
	 }
	 else if(slot > 9)
	 {
		if(state == 0)
		{
			PORTD |= (1<<(slot - 8));
		}
		else
		{
			PORTD &= ~(1<<(slot - 8));
		}
	 }
}

void loop() 
{
	// put your main code here, to run repeatedly:
	//
	//if(transmission_counter == -1)
		//return;
	if(Serial.available() > 0)
	{
		//toggle_pin(3, 1);
		if(slot == -1)
		{
			slot = Serial.read();
		}
		else
		{
			state = Serial.read();
		}

		if(state != -1)
		{
			toggle_pin(slot, state);

			slot = -1;
			state = -1;
		}
	}

}
