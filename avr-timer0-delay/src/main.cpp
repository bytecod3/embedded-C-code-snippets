
#include <avr/io.h>
#include <Arduino.h>

#define LED PD4

void t0_delay();

int main(void){
    Serial.begin(9600);

    uint8_t timerOverflowCount = 0;
    DDRD = 0xff; // configure PORTD as output

    while(1){

        PORTD = 0x55;
        t0_delay();
        PORTD = 0xAA;
        t0_delay();

    }


}


void t0_delay(){
    TCNT0 = 0x20; // load TCNT
    TCCR0A = 0x01; // timer 0, normal mode, no prescaler

    while((TIFR0 & 0x01) == 0); //wait for TIFR to roll_over
    TCCR0A = 0; // disable timer 0
    TIFR0 = 0x01; //clear TIFR

}