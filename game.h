#pragma once

#include <SFML/Window.hpp>
#include <vector>

class Player;
class Painter;
class View;

class Game {
private:
    Painter* painter_;

    std::vector<GameObject*> objects_;
    std::vector<View*> views_;
    
public: 
    Game(Painter* painter);
    void Draw();
    void ProcessKey(sf::Keyboard::Key key);
    void Tick(double dt);
};