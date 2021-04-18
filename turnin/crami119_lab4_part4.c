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



enum DB_States{DB_Wait, DB_ToUnlock1, DB_ToUnlock2, DB_Unlock, DB_Lock}DB_State;

void TickFct_DB(){

        switch(DB_State){ //transition state

        case DB_Wait:
        if(PINA == 0x04){
        DB_State = DB_ToUnlock1;
        }
	else if((PINA >> 7) == 0x01){
	DB_State = DB_Lock;
	}
        break;

        case DB_ToUnlock1:
	if(PINA == 0x00){
	DB_State = DB_ToUnlock2;
	}
	else if(PINA == 0x04){
	DB_State = DB_ToUnlock1;
	}
	else{
	DB_State = DB_Wait;
	}
        break;

	case DB_ToUnlock2:
	if((PINA == 0x02) && (PINB == 0x01)){
	DB_State = DB_Unlock;
	}
	else if((PINA == 0x02) && (PINB == 0x00)){
	DB_State = DB_Lock;	
	}
	else if(PINA == 0x00){
	DB_State = DB_ToUnlock2;
	}
	else{
	DB_State = DB_Wait;
	}
	break;

	case DB_Lock:
	case DB_Unlock:
	DB_State = DB_Wait;

        default:
        break;
        }

	switch(DB_State){ //state actions

	case DB_Unlock:
	PORTB = 0x01;
	break;

	case DB_Lock:
	PORTB = 0x00;
	break;

	case DB_Wait:
	case DB_ToUnlock1:
	case DB_ToUnlock2:
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
