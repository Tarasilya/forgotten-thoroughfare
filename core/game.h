#pragma once

#include <SFML/Window.hpp>
#include <vector>

class CollisionBox;
class GameObject;
class Player;
class Painter;
class View;

class Game {
private:
    Painter* painter_;

    std::vector<GameObject*> objects_;
    std::vector<View*> views_;
    
    void InitObjects();

public: 
    Game(Painter* painter);
    void Draw();
    void ProcessKey(sf::Keyboard::Key key);
    void Tick(double dt);
    std::vector<GameObject*>& GetCollision(CollisionBox* collision_box);
};