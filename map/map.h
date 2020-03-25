#pragma once

#include "objects/game_object.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

class CollisionBox;
class NullCollisionBox;
class TileView;

class Map : public GameObject {
private:
    std::vector<std::vector<TileView*>> map_;

    NullCollisionBox* null_collision_box_;
public:
    Map(std::string filename);

    CollisionBox* GetCollisionBox() override;
    void Tick(double dt) override;
    bool ProcessKey(sf::Keyboard::Key key, bool pressed) override;

};
