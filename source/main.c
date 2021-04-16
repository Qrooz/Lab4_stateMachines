/*	Author: crami119
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum LED_States{LED_Start, LED_ZeroOn, LED_ZeroOnWait, LED_OneOn, LED_OneOnWait}LED_State;

void TickFct_LED(){

        switch(LED_State){ //transition state
        case LED_Start:
        LED_State = LED_ZeroOn;
        break;

        case LED_ZeroOn:
        if(PINA == 0x00){
        LED_State = LED_ZeroOnWait;
        }
        break;

        case LED_ZeroOnWait:
        if(PINA == 0x01){
        LED_State = LED_OneOn;
        }
        break;

        case LED_OneOn:
        if(PINA == 0x00){
        LED_State = LED_OneOnWait;
        }
        break;

        case LED_OneOnWait:
        if(PINA == 0x01){
        LED_State = LED_ZeroOn;
        }
        break;

        default:
        break;
        }

	switch(LED_State){ //state actions

	case LED_ZeroOn:
	PORTB = 0x01;
	break;

	case LED_OneOn:
	PORTB = 0x02;
	break;

	case LED_Start:
	case LED_ZeroOnWait:
	case LED_OneOnWait:
	default:
	break;

	}

}


int main(void) {
    
	DDRA = 0x00;
	DDRB = 0xFF;

	LED_State = LED_Start;

    while (1) {

	TickFct_LED();

    }
    return 1;
}
