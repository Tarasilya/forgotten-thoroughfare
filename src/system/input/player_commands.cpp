#include "player_commands.h"

#include "component/state/input.h"
#include "component/state/player_commands.h"
#include "config_reader.h"

#include <iostream>


namespace systems {

PlayerCommands::PlayerCommands(SystemManager* manager)
        : Entityless(manager, "PlayerCommands") {
    InitUsedState();

    controls_ = ConfigReader("config.txt").GetControls();
}

void PlayerCommands::InitUsedState() {
    AddUsedState<component::Input>();
    AddUsedState<component::PlayerCommands>();
}

void PlayerCommands::Tick(double dt) {
    auto input = GetState<component::Input>();
    auto commands = GetState<component::PlayerCommands>();
    for (auto command : component::PLAYER_COMMANDS) {
        commands->Set(command.command, 
            (command.repeatable && input->Pressed(controls_[command.command]))
            || (!command.repeatable && input->PressedSingle(controls_[command.command])));
    }
}

}
