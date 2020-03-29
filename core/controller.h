#include <SFML/Graphics.hpp>

class Game;

class Controller {
private:
    Game* game_;
    sf::RenderWindow* window_;

    std::map<sf::Keyboard::Key, bool> pressed_keys_;

    void ProcessKey(sf::Keyboard::Key key, bool pressed);
    void ProcessPressedKeys();
public:
    void Run();
};