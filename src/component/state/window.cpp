#include "window.h"


namespace component {

void Window::Init(int width, int height) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height), "FT");
}

sf::RenderWindow* Window::GetWindow() {
    return window_;
}

}
