#pragma once

#include <SFML/Window.hpp>
#include <vector>

class CollisionBox;
class GameObject;
class Player;
class View;

class Game {
private:
    static Game* current_game_;

    std::vector<GameObject*> objects_;
    std::vector<View*> views_;
    
    void InitObjects();
    void InitMap();

public: 
    static void StartGame();
    static void StopGame();
    static Game* GetCurrentGame();

    Game();
    void ProcessKey(sf::Keyboard::Key key, bool pressed);
    void Tick(double dt);
    void AddObject(GameObject* object);
    void AddView(View* view);
    std::vector<GameObject*>& GetCollision(CollisionBox* collision_box);
};