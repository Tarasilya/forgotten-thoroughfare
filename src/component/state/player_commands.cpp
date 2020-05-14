#include "player_commands.h"


namespace component {

void PlayerCommands::Set(std::string command, bool value) {
    commands_[command] = value;
}
bool PlayerCommands::Get(std::string command) {
    return commands_[command];
}

}
