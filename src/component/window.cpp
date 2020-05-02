#include "window.h"

void Window::Init(int width, int height) {
    window_ = new sf::RenderWindow(sf::VideoMode(width, height), "FT");
}

Window::~Window() {}

sf::RenderWindow* Window::GetWindow() {
    return window_;
}
