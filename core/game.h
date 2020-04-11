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
    
    void InitObjects();
    void InitMap();

public: 
    static void StartGame();
    static void StopGame();
    static Game* GetGame();

    void ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated);
    void Tick(double dt);
    void AddObject(GameObject* object);
    std::vector<GameObject*>& GetCollision(CollisionBox* collision_box);
};