#pragma once 

#include "component/component.h"
#include "component/key_state.h"

#include <SFML/Window.hpp>

#include <map>

namespace component {

class Input: public Component {
private:
    std::map<sf::Keyboard::Key, KeyState> key_state_;
public:
    void UpdateKey(sf::Keyboard::Key key, bool new_state);
    void AddKey(sf::Keyboard::Key key);
    bool Pressed(sf::Keyboard::Key key);
    bool PressedSingle(sf::Keyboard::Key key);
    const std::map<sf::Keyboard::Key, KeyState>& GetKeyStates();
};

}
