#pragma once
#include "LightState.h"

class  Light {
private:
    LightState currentState  = LightState::Off; // direct initialization
public:
    Light() {};
    void toggle() {
        this->currentState = lightTransitions[this->currentState];

    }
};
