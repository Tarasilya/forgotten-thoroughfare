#include <SFML/Graphics.hpp>

#include <string>

class Client;
class Game;

class Controller {
private:
    Client* client_;
    Game* game_;
    sf::RenderWindow* window_;

    std::map<sf::Keyboard::Key, bool> pressed_keys_;

    void ProcessKey(sf::Keyboard::Key key, bool pressed);
    void ProcessPressedKeys();
    void SendAction(const std::string& action);
public:
    void Run();
};