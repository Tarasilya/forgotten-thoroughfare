#include "component/collision_rect.h"
#include "component/player.h"
#include "component/sprite_drawable.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "component/state/input.h"
#include "component/state/window.h"
#include "entity.h"
#include "system/collision_detection.h"
#include "system/collision_resolve.h"
#include "system/movement_apply.h"
#include "system/player_movement.h"
#include "system/rendering.h"
#include "system/system.h"
#include "system/system_manager.h"
#include "system/entityless/input.h"
#include "textures.h"

#include <chrono>
#include <iostream>
#include <thread>

const double MIN_FRAME = 16;

void InitRat(Entity* rat, component::Window* window) {
    rat->AddComponent(new component::SpriteDrawable("pics/default_warrior2.png"));
    double size = 0.2;
    auto scale = Textures::GetScaleForSize("pics/default_warrior2.png", size, size, window);
    rat->AddComponent(new component::Transform(0.5, 0.5, 0, scale.first, scale.second));
    rat->AddComponent(new component::Player());
    rat->AddComponent(new component::Unpassable());
    rat->AddComponent(new component::CollisionRect(size, size));
}

int main() {
    auto system_manager = new systems::SystemManager();
    auto window = new component::Window();
    system_manager->AddComponentToState(window);
    system_manager->AddComponentToState(new component::Input());

    system_manager->AddSystem(new systems::Input(system_manager));
    system_manager->AddSystem(new systems::PlayerMovement(system_manager));
    system_manager->AddSystem(new systems::CollisionDetection(system_manager));
    system_manager->AddSystem(new systems::CollisionResolve(system_manager));
    system_manager->AddSystem(new systems::MovementApply(system_manager));
    system_manager->AddSystem(new systems::Rendering(system_manager));

    Entity* rat = new Entity("rat");
    InitRat(rat, window);
    system_manager->AddEntity(rat);

    Entity* punching_bag = new Entity("punching_bag");
    double p_size = 0.1;
    auto scale = Textures::GetScaleForSize("pics/punch_bag.png", p_size, p_size, window);
    punching_bag->AddComponent(new component::SpriteDrawable("pics/punch_bag.png"));
    punching_bag->AddComponent(new component::CollisionRect(p_size, p_size));
    punching_bag->AddComponent(new component::Transform(0.0, 0.3, 0, scale.first, scale.second));
    system_manager->AddEntity(punching_bag);
    Entity* punching_bag2 = new Entity("punching_bag_2");
    punching_bag2->AddComponent(new component::SpriteDrawable("pics/punch_bag.png"));
    punching_bag2->AddComponent(new component::CollisionRect(p_size, p_size));
    punching_bag2->AddComponent(new component::Transform(0.3000000001, 0.3, 0, scale.first, scale.second));
    system_manager->AddEntity(punching_bag2);
    Entity* punching_bag3 = new Entity("punching_bag_3");
    punching_bag3->AddComponent(new component::SpriteDrawable("pics/punch_bag.png"));
    punching_bag3->AddComponent(new component::CollisionRect(p_size, p_size));
    punching_bag3->AddComponent(new component::Transform(0.5000000001, 0.3, 0, scale.first, scale.second));
    system_manager->AddEntity(punching_bag3);

    auto prev_t = std::chrono::high_resolution_clock::now();

    int frames = 0;

    while (window->GetWindow()->isOpen()) {
        auto cur = std::chrono::high_resolution_clock::now();
        double dt = std::chrono::duration_cast<std::chrono::milliseconds>(cur - prev_t).count();
        if (dt > MIN_FRAME) {
            prev_t = cur;
            frames ++;
            system_manager->Tick(dt);
        }
    }
}
