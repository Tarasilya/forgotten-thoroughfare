#include "window_system.h"
#include "system_manager.h"

#include "component/window.h"

#include <SFML/Graphics.hpp>


WindowSystem::WindowSystem(SystemManager* manager): System(manager) {}

void WindowSystem::Tick(double dt) {
    auto window = system_manager_->GetComponentFromState<Window>()->GetWindow();

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
            break;
        }
    }
}
