/**
* Simulates a light bulb as a state machine that can be in
 * any of the following 4 state machines
 *
 * OFF
 * LOW
 * MEDIUM
 * HIGH
 *
*/
#include <iostream>
#include <array>

enum LightState {
    Off = 0,
    Low = 1,
    Medium = 2,
    High = 3
};

std::array<LightState, 4> states{
    LightState::Off,
    LightState::Low,
    LightState::Medium,
    LightState::High
};

LightState state = states[0]; // initial state OFF

void toggle() {
    state = states[(state + 1) % 4];
}

int main() {
    std::cout << "initial state: " << state  << std::endl;
    toggle();
    std::cout << "current state: " << state  << std::endl;

    toggle();
    std::cout << "current state: " << state  << std::endl;

    toggle();
    std::cout << "current state: " << state  << std::endl;

    toggle();
    std::cout << "current state: " << state << std::endl ;

    toggle();
    std::cout << "current state: " << state  << std::endl;

    return 0;
}