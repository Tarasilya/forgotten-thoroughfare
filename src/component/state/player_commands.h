#pragma once 

#include "component/component.h"

#include <map>
#include <string>
#include <vector>


namespace component {

struct Command {
    std::string command;
    bool repeatable;
};

const std::string UP = "up";
const std::string DOWN = "down";
const std::string LEFT = "left";
const std::string RIGHT = "right";
const std::string ATTACK = "attack";
const std::string TOGGLE_CRAFT = "toggle_craft";
const std::string TOGGLE_BACKPACK = "toggle_backpack";
const std::vector<Command> PLAYER_COMMANDS = 
    {
        {UP, true}, 
        {DOWN, true},
        {LEFT, true},
        {RIGHT, true},
        {ATTACK, true},
        {TOGGLE_CRAFT, false},
        {TOGGLE_BACKPACK, false}
    };

class PlayerCommands: public Component {
private:
    std::map<std::string, bool> commands_;
public:
    void Set(std::string command, bool value);
    bool Get(std::string command);
};

}
