#include "player_movement.h"

#include "component/movement.h"
#include "component/player.h"
#include "component/transform.h"
#include "component/state/input.h"


namespace systems {

PlayerMovement::PlayerMovement(SystemManager* manager)
        : System(manager, "PlayerMovement") {
    InitRequiredComponents();
    InitUsedState();
}


void PlayerMovement::InitRequiredComponents() {
    AddRequiredComponent<component::Player>();
}

void PlayerMovement::InitUsedState() {
    AddUsedState<component::Input>();
}

const double SPEED = 0.0003;

void PlayerMovement::Tick(double dt) {
    auto key_states = GetState<component::Input>()->GetKeyStates();
    for (auto entity: Entities()) {
        double x_speed = 0;
        double y_speed = 0;

        if (key_states[sf::Keyboard::Up].current) {
            y_speed -= SPEED;
        }
        if (key_states[sf::Keyboard::Down].current) {
            y_speed += SPEED;
        }
        if (key_states[sf::Keyboard::Right].current) {
            x_speed += SPEED;
        }
        if (key_states[sf::Keyboard::Left].current) {
            x_speed -= SPEED;
        }

        entity->AddComponent(
            new component::Movement(x_speed * dt, y_speed * dt));
        system_manager_->ComponentAdded<component::Movement>(entity);
    }
}

}
