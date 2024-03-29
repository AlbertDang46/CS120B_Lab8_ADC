/*	Author: Albert Dang adang018
 *      Partner(s) Name: Min-Hua Wu mwu057
 *	Lab Section: 022
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short output;
const unsigned short lightMax = 96;

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;

    ADC_init();

    while (1) {
        output = ADC;
        // PORTB = (char)output;
        // PORTD = (char)(output >> 8);
        PORTB = (output >= (lightMax / 2)) ? 1 : 0;
    }
    return 1;
}
