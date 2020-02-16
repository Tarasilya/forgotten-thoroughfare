#include <SFML/Graphics.hpp>

class Game;

class Controller {
private:
    Game* game_;
    sf::RenderWindow* window_;
    void ProcessKey(sf::Keyboard::Key key, bool pressed);
public:
    void Run();
};