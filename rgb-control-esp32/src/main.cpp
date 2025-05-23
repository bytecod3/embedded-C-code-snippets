#include <Arduino.h>
#include <ledc.h>

enum RGB_PINS{
    RED = 13,
    GREEN = 12,
    BLUE = 27
};

//enum RGB_PINS rgb_pins;

void initRGB() {
    pinMode(RGB_PINS::RED, OUTPUT);
    pinMode(RGB_PINS::GREEN, OUTPUT);
    pinMode(RGB_PINS::BLUE, OUTPUT);
}

void setup() {
    initRGB();
    ledcSetup(ledChannel)
    ledcAttach
}

void loop() {

}