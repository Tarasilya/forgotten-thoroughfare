#include "game.h"

#include "component/collision_rect.h"
#include "component/backpack.h"
#include "component/craft/craft.h"
#include "component/craft/recipe.h"
#include "component/player.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/unpassable.h"
#include "component/state/input.h"
#include "component/state/player_commands.h"
#include "component/state/window.h"
#include "entity.h"
#include "map.h"
#include "system/attack.h"
#include "system/bc_visibility.h"
#include "system/camera/camera.h"
#include "system/camera/camera_apply.h"
#include "system/camera/camera_movement.h"
#include "system/collision/collision_detection.h"
#include "system/collision/collision_resolve.h"
#include "system/input/input.h"
#include "system/input/player_commands.h"
#include "system/movement/movement_apply.h"
#include "system/movement/player_movement.h"
#include "system/render/render_vector.h"
#include "system/render/renderer.h"
#include "system/render/sprite_pre_render.h"
#include "system/render/text_pre_render.h"
#include "system/system.h"
#include "system/system_manager.h"
#include "textures.h"

#include <chrono>
#include <iostream>
#include <thread>

const int MIN_FRAME = 16;


Game::Game() {
    system_manager_ = new systems::SystemManager();
    InitState();
    InitSystems();
    InitRat();
    InitPunchingBags();
    new Map("maps/dumb.map", system_manager_);
}

void Game::InitState() {
    int size = sf::VideoMode::getDesktopMode().height * 0.9;
    system_manager_->AddComponentToState(new component::Camera());
    system_manager_->AddComponentToState(new component::Window(size, size));
    system_manager_->AddComponentToState(new component::Input());
    system_manager_->AddComponentToState(new component::PlayerCommands());
    system_manager_->AddComponentToState(new component::RenderVector());
}

void Game::InitSystems() {
    system_manager_->AddSystem(new systems::Input(system_manager_));
    system_manager_->AddSystem(new systems::PlayerCommands(system_manager_));

    system_manager_->AddSystem(new systems::PlayerMovement(system_manager_));
    system_manager_->AddSystem(new systems::BCVisibility(system_manager_));
    system_manager_->AddSystem(new systems::Attack(system_manager_));
    system_manager_->AddSystem(new systems::CollisionDetection(system_manager_));
    system_manager_->AddSystem(new systems::CollisionResolve(system_manager_));
    system_manager_->AddSystem(new systems::MovementApply(system_manager_));

    system_manager_->AddSystem(new systems::CameraMovement(system_manager_));
    system_manager_->AddSystem(new systems::TextPreRender(system_manager_));
    system_manager_->AddSystem(new systems::SpritePreRender(system_manager_));
    system_manager_->AddSystem(new systems::CameraApply(system_manager_));
    system_manager_->AddSystem(new systems::Renderer(system_manager_));
}

void Game::Run() {
    auto window = system_manager_->GetComponentFromState<component::Window>();

    auto prev_t = std::chrono::high_resolution_clock::now();

    while (window->GetWindow()->isOpen()) {
        auto cur = std::chrono::high_resolution_clock::now();
        double dt = std::chrono::duration_cast<std::chrono::milliseconds>(cur - prev_t).count();
        if (dt > MIN_FRAME) {
            prev_t = cur;
            system_manager_->Tick(dt);
        }
    }
}

void Game::InitPunchingBags() {
    double x[] = {0, 0.3000001, 0.5000001};
    double p_size = 0.1;
    for (int i = 0; i < 3; i++) {
        Entity* punching_bag = new Entity("punching_bag_" + std::to_string(i));
        punching_bag->AddComponent(new component::Sprite("pics/punch_bag.png", p_size, p_size, 1));
        punching_bag->AddComponent(new component::CollisionRect(p_size, p_size));
        punching_bag->AddComponent(new component::Transform(x[i], 0.3));
        if (i % 2) {
            punching_bag->AddComponent(new component::Unpassable());
        }
        system_manager_->AddEntity(punching_bag);
    }
}

void Game::InitRat() {
    Entity* rat = new Entity("rat");
    double size = 0.2;
    rat->AddComponent(new component::Sprite("pics/default_warrior2.png", size, size, 5));
    rat->AddComponent(new component::Transform(0.5, 0.4));
    rat->AddComponent(new component::Unpassable());
    rat->AddComponent(new component::CollisionRect(size, size));
    rat->AddComponent(new component::Player());
    rat->AddComponent(new component::Backpack());
    rat->AddComponent(new component::Craft(std::map<std::string, Recipe>()));
    system_manager_->AddEntity(rat);
}