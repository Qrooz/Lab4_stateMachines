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


	unsigned char i = 0x00;
        char unlockSeq[4]={0x04, 0x01, 0x02, 0x01};


enum DB_States{DB_Wait, DB_Unlocking, DB_Release, DB_Trigger}DB_State;

void TickFct_DB(){

        switch(DB_State){ //transition state
     
	case DB_Wait:
	if(PINA == unlockSeq[i]){
	DB_State = DB_Unlocking;
	}
	else if((PINA >> 7) == 0x01){
	DB_State = DB_Trigger;
	}
	break;

	case DB_Unlocking:	
	if(i == 2){
	DB_State = DB_Trigger;
	}	
	else if(PINA == unlockSeq[i]){
	DB_State = DB_Unlocking;
	}
	else if(PINA == 0x00){
	DB_State = DB_Release;
	++i;
	}
	else{
	DB_State = DB_Wait;
	}
	break;

	case DB_Release:
	if(PINA == 0x00){
	DB_State = DB_Release;
	}
	else if(PINA == unlockSeq[i]){
	DB_State = DB_Unlocking;
	}
	else{
	DB_State = DB_Wait;
	}
	break;

	case DB_Trigger:
	DB_State = DB_Wait;
	default:
	break;
	}

	switch(DB_State){ //state actions

	case DB_Wait:
	i = 0x00;
	break;

	case DB_Trigger:
	if((PINA >> 7) == 0x01){
	PORTB = 0x00;
	}
	else if(PORTB == 0x00){
	PORTB = 0x01;
	}
	else if(PORTB == 0x01){
	PORTB = 0x00;
	}
	break;

	default:
	break;
	
	}
}


int main(void) {
    
	DDRA = 0x00;
	DDRB = 0xFF;

	PORTB = 0x00;
	DB_State = DB_Wait;

    while (1) {

	TickFct_DB();

    }
    return 1;
}
