#pragma once

struct PlayerAction {
    std::string action_id;
    sf::Keyboard::Key key;
    std::function runnable;
    bool allow_repeated;
    bool on_press = true;
};

class PlayerActionController {
private:
    std::vector<PlayerAction> actions_;

public:
    void AddAction(PlayerAction action);

    void TriggerAction(std::string action_id);

    void GetActionId(sf::Keyboar::Key key);
};