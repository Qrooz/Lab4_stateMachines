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
        char userInput[4]={0x00, 0x00, 0x00, 0x00};
	char temp = 0xFF;


enum DB_States{DB_Wait, DB_Unlock, DB_Lock}DB_State;

void TickFct_DB(){

        switch(DB_State){ //transition state
     
	case DB_Wait:
	if(PINA == temp){
	DB_State = DB_Wait;
	}
	else if(unlockSeq == userInput){
	DB_State = DB_Unlock; 
	}
	else if(PINA == 0x00){
	DB_State = DB_Wait;
	}
	else if((PINA >> 7) == 0x01){
	DB_State = DB_Lock;
	}
	temp = PINA;
	break;

	case DB_Unlock:	
	DB_State = DB_Wait;	
	break;

	case DB_Lock:
	DB_State = DB_Wait;
	break;

	default:
	break;
	}

	switch(DB_State){ //state actions

	case DB_Wait:
	if(PINA != 0x00){
	userInput[i] = PINA;
	}
	else if(PINA == 0x00){}
	if(userInput[i] != unlockSeq[i]){

        userInput[0] = 0x00;
        userInput[1] = 0x00;
        userInput[2] = 0x00;
        userInput[3] = 0x00;
        i = 0x00;
        }
	if(PINA != 0x00){
        ++i;
        }
	break;

	case DB_Unlock:
	PORTB = 0x01;
	break;

	case DB_Lock:
	PORTB = 0x00;
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
