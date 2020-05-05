#include "input.h"

#include "component/state/input.h"
#include "component/state/window.h"


namespace systems {

Input::Input(SystemManager* manager)
        : Entityless(manager, "Input") {
    InitUsedState();
}

void Input::InitUsedState() {
    AddUsedState<component::Input>();
    AddUsedState<component::Window>();
}


void Input::Tick(double dt) {
    auto input = GetState<component::Input>();
    auto window = GetState<component::Window>()->GetWindow();

    std::map<sf::Keyboard::Key, bool> key_changes;

    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }
                key_changes[event.key.code] = true;
                input->AddKey(event.key.code);
                break;
            case sf::Event::KeyReleased:
                key_changes[event.key.code] = false;
                break;
            default:
                ;
        }
    }

    for (auto const& [key, state]: input->GetKeyStates()) {
        if (key_changes.find(key) != key_changes.end()) {
            input->UpdateKey(key, key_changes[key]);    
        }
        else {
            input->UpdateKey(key, state.current);
        }
        
    }
}

}
