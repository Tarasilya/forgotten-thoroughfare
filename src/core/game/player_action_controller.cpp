#include "player_action_controller.h"

#include <functional>

void PlayerActionController::AddAction(PlayerAction action) {
    actions_.push_back(action);
}

void PlayerActionController::TriggerAction(std::string action_id, Player* player) {
    for (auto action : actions_) {
        if (action.action_id == action_id) {
            std::invoke(action.runnable, player);
        }
    }
}

std::string PlayerActionController::GetActionId(sf::Keyboard::Key key, bool pressed, bool repeated) {
    for (auto action : actions_) {
        if (action.key == key
                && (!repeated || action.allow_repeated)
                && action.on_press == pressed) {
            return action.action_id;
        }
    }
    return "";
}
