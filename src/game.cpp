#include "game.h"

#include "component/collision_rect.h"
#include "component/hp.h"
#include "component/mouse.h"
#include "component/sprite.h"
#include "component/transform.h"
#include "component/state/input.h"
#include "component/state/map.h"
#include "component/state/player_commands.h"
#include "component/state/window.h"
#include "component/unit.h"
#include "entity.h"
#include "system/camera/camera.h"
#include "system/camera/camera_apply.h"
#include "system/camera/camera_movement.h"
#include "system/collision/collision_detection.h"
#include "system/collision/collision_resolve.h"
#include "system/input/keyboard_input.h"
#include "system/input/mouse_input.h"
#include "system/input/player_commands.h"
#include "system/movement/execute_unit_movement.h"
#include "system/movement/movement_apply.h"
#include "system/movement/order_unit_movement.h"
#include "system/render/render_vector.h"
#include "system/render/renderer.h"
#include "system/render/sprite_pre_render.h"
#include "system/render/text_pre_render.h"
#include "system/render/rectangle_pre_render.h"
#include "system/select/select.h"
#include "system/system.h"
#include "system/system_manager.h"

#include <chrono>
#include <iostream>
#include <thread>

const int MIN_FRAME = 16;


Game::Game() {
    system_manager_ = new systems::SystemManager();
    InitState();
    InitSystems();
    system_manager_->AddComponentToState(new component::Map(system_manager_, "maps/dumb.map"));
    auto unit = new Entity("unit");
    unit->AddComponent(new component::Transform(-0.05, -0.05));
    unit->AddComponent(new component::CollisionRect(component::TILE_SIZE / 2, component::TILE_SIZE / 2));
    unit->AddComponent(new component::Unit());
    unit->AddComponent(
        new component::Sprite(
                "pics/rat.png", 
                component::TILE_SIZE / 2, 
                component::TILE_SIZE / 2,
                1));
    auto hp = new component::Hp(100, unit, system_manager_);
    unit->AddComponent(hp);
    hp->Change(-30);
    system_manager_->AddEntity(unit);
    auto mouse = new Entity("mouse");
    mouse->AddComponent(new component::Transform());
    mouse->AddComponent(new component::Mouse());
    mouse->AddComponent(new component::CollisionRect(0, 0));
    system_manager_->AddEntity(mouse);
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
    system_manager_->AddSystem(new systems::KeyboardInput(system_manager_));
    system_manager_->AddSystem(new systems::MouseInput(system_manager_));
    system_manager_->AddSystem(new systems::PlayerCommands(system_manager_));

    system_manager_->AddSystem(new systems::CollisionDetection(system_manager_));
    system_manager_->AddSystem(new systems::Select(system_manager_));
    system_manager_->AddSystem(new systems::OrderUnitMovement(system_manager_));
    system_manager_->AddSystem(new systems::ExecuteUnitMovement(system_manager_));
    //system_manager_->AddSystem(new systems::CollisionResolve(system_manager_));
    //system_manager_->AddSystem(new systems::MovementApply(system_manager_));

    system_manager_->AddSystem(new systems::CameraMovement(system_manager_));
    system_manager_->AddSystem(new systems::TextPreRender(system_manager_));
    system_manager_->AddSystem(new systems::SpritePreRender(system_manager_));
    system_manager_->AddSystem(new systems::RectanglePreRender(system_manager_));
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

