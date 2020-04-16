#pragma once

#include "control_keys.h"

#include <SFML/Window.hpp>

#include <map>
#include <string>

class ConfigReader {
private:
    std::map<std::string, std::string> params_;

    sf::Keyboard::Key GetKey(std::string);

public:
    GameConfig();

    std::map<sf::Keyboard::Key, Control> GetControls(int player_index);
    std::string GetString(std::string name);
    int GetInt(std::string name);
    float GetFloat(std::string name);
};
