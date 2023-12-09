/**
 * This program set TIMER1 to generate a PWM signal using Fast PWM mode - 8 bit
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define DUTY_CYCLE 50
#define OCR_VALUE ( (DUTY_CYCLE * 256) / 100 )  // OCR value calculation


void timer1_fast_pwm_init();

int main(){

    // initialize timer1
    timer1_fast_pwm_init();

    // set global interrupts
    sei();

    while(1);

}


void timer1_fast_pwm_init(){
    // set mode to fast PWM 8 bit
    TCCR1A |= (1<<WGM10);
    TCCR1A |= (1<<WGM12);

    // set prescaler value to 1024
    TCCR1B |= (1<<CS12);
    TCCR1B |= (1<<CS10);

    // set non-inverting mode
    TCCR1A |= (1<<COM1A1);
    TCCR1A |= (0<<COM1A0);

    // set OC1A as output - pin from datasheet
    DDRB |= (1<<PINB1);

    // enable interrupts for TIMER1
    TIMSK1 |= (1<<OCIE0A);

}

// set interrupt service routines;
ISR(TIMER1_COMPA_vect){
    // write OCRIA value to pin
    OCR1A = OCR_VALUE;
}

