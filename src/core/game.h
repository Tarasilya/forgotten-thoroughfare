#pragma once

#include <SFML/Window.hpp>

#include <string>
#include <vector>

class CollisionBox;
class GameObject;
class Player;
class PlayerActionController;
class View;

class Game {
private:
    Player* player1_;
    Player* player2_;
    static Game* current_game_;

    std::vector<GameObject*> objects_;
    PlayerActionController* action_controller_;
    
    void InitObjects();
    void InitMap();
    void InitPlayer();
    void InitPlayerControls();
public: 
    static void StartGame();
    static void StopGame();
    static Game* GetGame();

    std::string ProcessKey(sf::Keyboard::Key key, bool pressed, bool repeated);
    void ProcessAction(const std::string& action);

    void Tick(double dt);
    void AddObject(GameObject* object);
    std::vector<GameObject*>& GetCollision(CollisionBox* collision_box);
};