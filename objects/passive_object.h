#pragma once

#include "objects/game_object.h"

class PassiveObject : public GameObject {
public:
    bool ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated) override;
};
