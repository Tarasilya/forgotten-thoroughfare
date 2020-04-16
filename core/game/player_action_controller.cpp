#include "player_action_controller.h"

struct PlayerAction {
    std::string action_id;
    sf::Keyboard::Key key;
    std::function runnable;
    bool allow_repeated;
    bool on_press = true;
};

    std::vector<PlayerAction> actions_;

void PlayerActionController::AddAction(PlayerAction action) {
    actions_.push_back(action);
}

void PlayerActionController::TriggerAction(std::string action_id, bool pressed, bool repeated) {
    for (auto action : actions_) {
        if (action.action_id == action_id 
                && (!repeated || action.allow_repeated)
                && action.on_press == pressed) {
            action.runnable();       
        }
    }
}

void PlayerActionController::GetActionId(sf::Keyboar::Key key) {
    for (auto action : actions_) {
        if (action.key == key) {
            return action.action_id;
        }
    }
}
