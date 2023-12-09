
/**
 * This program will toggle the state of an LED after 1.5 sec
 * using TIMER1 interrupts
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int state = 0;

// set up the ISR for TIMER1
ISR(TIMER1_COMPA_vect){
    state = state + 1;
    state = state % 2; // toggle state: 1->0; 0->1

    // toggle LED
    PORTD ^= (1<<PIND4);


}


int main(){
    // set PORTD as output
    //DDRD |= (1<<PIND4);
    //PORTD |= (1<<PIND4);

    //PORTD = 0xff;
    //DDRD = 0xff;

    DDRD |= (1 << PIND4);
    PORTD |= (1 << PIND4);

    // clear control register A
    TCCR1A = 0x00;

    // clear control register B
    TCCR1B = 0x00;

    // set bit for CTC(clear timer on compare match)
    TCCR1B |= (1<<WGM12);

    // set clock prescaler tp /1024
    TCCR1B |= (1<<CS12);
    TCCR1B |= (1<<CS10);

    // set OCR1A to 23427 - corresponds to 1.5 sec
    OCR1A = 23437;

    // enable interrupt on OCR1A
    TIMSK1 |= (1<<OCIE1A);

    TCNT1 = 0; // reset counter to 0
    sei();

    while(1){
        // give a reasonable DELAY
        _delay_ms(10000);

    }

}