#include <avr/interrupt.h>

// define ISR for timer0 overflow
ISR(TIMER0_OVF_vect){
    // process the timer0 overflow here
    PORTD = PORTD ^ 0x02; // XOR portd to toggle the LSB
}

ISR(TIMER1_OVF_vect){
    PORTD = PORTD ^ 0x01; // xor portD to toggle the second bit up
}


int main(){
    // configure port D as output
    DDRD = 0xFF;
    PORTD = 0xFF;

    // enable timer overflow interrupt for timer0
    TIMSK0 = (1 << TOIE0);

    // set timer0 initial count to 0
    TCNT0 = 0x00;

    // start timer0 with a /1024 pre-scaler
    TCCR0A = (1<<CS02) | (1<<CS00);

    // enable global interrupts
    sei();

    while(1){
        // main loop

    }
}