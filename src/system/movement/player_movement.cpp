#include "player_movement.h"

#include "component/attack.h"
#include "component/movement.h"
#include "component/parent_entity.h"
#include "component/player.h"
#include "component/transform.h"
#include "component/sprite.h"
#include "component/state/player_commands.h"

#include <cmath>


namespace systems {

PlayerMovement::PlayerMovement(SystemManager* manager)
        : System(manager, "PlayerMovement") {
    InitRequiredComponents();
    InitUsedState();
}


void PlayerMovement::InitRequiredComponents() {
    AddRequiredComponent<component::Player>();
    AddRequiredComponent<component::Transform>();
}

void PlayerMovement::InitUsedState() {
    AddUsedState<component::PlayerCommands>();
}

const double SPEED = 0.0003;
const double EPS = 1e-9;

void PlayerMovement::Tick(double dt) {
    auto player_commands = GetState<component::PlayerCommands>();
    for (auto entity: Entities()) {
        auto transform = GetComponent<component::Transform>(entity);
        double x_speed = 0;
        double y_speed = 0;

        if (player_commands->Get(component::UP)) {
            y_speed -= SPEED;
        }
        if (player_commands->Get(component::DOWN)) {
            y_speed += SPEED;
        }
        if (player_commands->Get(component::RIGHT)) {
            x_speed += SPEED;
            transform->SetScaleX(abs(transform->GetScaleX()));
        }
        if (player_commands->Get(component::LEFT)) {
            x_speed -= SPEED;
            transform->SetScaleX(-abs(transform->GetScaleX()));
        }
        if (player_commands->Get(component::ATTACK)) {
            if (!entity->HasComponent<component::Attack>()) {
                CreateAttack(entity);
            }
        }

        if (abs(x_speed) + abs(y_speed) > EPS) {
            system_manager_->AddComponent(
                entity, new component::Movement(x_speed * dt, y_speed * dt));
        }
    }
}

void PlayerMovement::CreateAttack(Entity* entity) {
    std::cerr << "CreateAttack start" << std::endl;

    Entity* attack = new Entity("attack");
    attack->AddComponent(new component::ParentEntity(entity));
    attack->AddComponent(new component::Transform());
    double width = 0.1;
    double height = 0.03;
    attack->AddComponent(new component::Sprite("pics/supercool_sword.png", width, height, 6));
    system_manager_->AddEntity(attack);
    system_manager_->AddComponent(entity, new component::Attack(attack, 0.1));
    std::cerr << "CreateAttack finish" << std::endl;
}

}
