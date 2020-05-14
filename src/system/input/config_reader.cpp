#include "config_reader.h"

#include "control_keys.h"
#include "component/state/player_commands.h"

#include <iostream>
#include <fstream>

ConfigReader::ConfigReader(const std::string& filename) {
    std::ifstream in(filename);
    std::string name, value;
    while (in >> name) {
        in >> value;
        std::cerr << "read " << name << " " << value << std::endl;
        params_[name] = value;
    }
}

std::string ConfigReader::GetString(std::string name) {
    return params_[name];
}

int ConfigReader::GetInt(std::string name) {
    return std::stoi(params_[name]);
}

float ConfigReader::GetFloat(std::string name) {
    return std::stof(params_[name]);
}


std::map<std::string, sf::Keyboard::Key> ConfigReader::GetControls() {
    std::map<std::string, sf::Keyboard::Key> controls_;

    for (auto command : component::PLAYER_COMMANDS) {
        controls_[command.command] = GetKey(command.command);    
    }
    
    return controls_;
}

sf::Keyboard::Key ConfigReader::GetKey(std::string name) {
    return ToSfKey(params_[name]);
}