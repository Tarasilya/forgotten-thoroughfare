#include "window.h"


namespace component {

Window::Window(int width, int height) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height), "FT");
}

sf::RenderWindow* Window::GetWindow() {
    return window_;
}

}
