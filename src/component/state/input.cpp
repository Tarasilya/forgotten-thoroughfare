#include "input.h"

#include <iostream>


namespace component {

void Input::UpdateKey(sf::Keyboard::Key key, bool new_state) {
    auto& state = key_state_[key];
    state.previous = state.current;
    state.current = new_state;
}

const std::map<sf::Keyboard::Key, KeyState>& Input::GetKeyStates() {
    return key_state_;
}

bool Input::Pressed(sf::Keyboard::Key key) {
    return key_state_[key].current;
}

bool Input::PressedSingle(sf::Keyboard::Key key) {
    auto state = key_state_[key];
    return state.current && !state.previous;
}

void Input::AddKey(sf::Keyboard::Key key) {
    if (key_state_.find(key) == key_state_.end()) {
        key_state_[key] = {false, false};
    }
}

}
