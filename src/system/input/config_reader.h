#pragma once

#include <SFML/Window.hpp>

#include <map>
#include <string>

class ConfigReader {
private:
    std::map<std::string, std::string> params_;

    sf::Keyboard::Key GetKey(std::string);

public:
    ConfigReader(const std::string& filename);

    std::map<std::string, sf::Keyboard::Key> GetControls();
    std::string GetString(std::string name);
    int GetInt(std::string name);
    float GetFloat(std::string name);
};