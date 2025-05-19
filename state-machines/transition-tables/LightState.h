#pragma once
#include <map>

enum class LightState {
    Off,
    Low,
    Medium,
    High
};

std::map<LightState, LightState> lightTransitions = {
        {LightState::Off, LightState::Low},
        {LightState::Low, LightState::Medium},
        {LightState::Medium, LightState::High},
        {LightState::High, LightState::Off},
};