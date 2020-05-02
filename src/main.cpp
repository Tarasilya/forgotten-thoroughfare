#include "component/sprite_drawable.h"
#include "component/window.h"
#include "entity.h"
#include "system/render_system.h"
#include "system/system.h"
#include "system/system_manager.h"
#include "system/window_system.h"

#include <chrono>
#include <iostream>
#include <thread>

const double MIN_FRAME = 16;

int main() {
    SystemManager* system_manager = new SystemManager();
    auto window = new Window();
    system_manager->AddComponentToState(window);

    system_manager->AddSystem(new RenderSystem(system_manager));
    system_manager->AddSystem(new WindowSystem(system_manager));

    Entity* rat = new Entity();
    rat->AddComponent(new SpriteDrawable("pics/default_warrior2.png"));
    system_manager->AddEntity(rat);

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