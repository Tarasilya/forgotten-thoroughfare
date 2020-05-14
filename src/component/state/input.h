#pragma once 

#include "component/component.h"

#include <SFML/Window.hpp>

#include <map>

namespace component {


struct KeyState {
    bool previous;
    bool current;
};

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
