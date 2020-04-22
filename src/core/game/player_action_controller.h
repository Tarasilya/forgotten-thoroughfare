#pragma once

#include "objects/player.h"

#include <SFML/Window.hpp>

#include <string>

struct PlayerAction {
    std::string action_id;
    sf::Keyboard::Key key;
    bool allow_repeated;
    void (Player::*runnable)();
    bool on_press = true;
};

class PlayerActionController {
private:
    std::vector<PlayerAction> actions_;

public:
    void AddAction(PlayerAction action);

    void TriggerAction(std::string action_id, Player* player);

    std::string GetActionId(sf::Keyboard::Key key, bool pressed, bool repeated);
};