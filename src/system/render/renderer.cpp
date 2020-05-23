#include "renderer.h"

#include "component/state/window.h"
#include "drawable/drawable.h"
#include "render_vector.h"

#include <SFML/Graphics.hpp>


namespace systems {

Renderer::Renderer(SystemManager* manager)
        : System(manager, "Renderer") {
    InitUsedState();
}

void Renderer::InitUsedState() {
    AddUsedState<component::Window>();
    AddUsedState<component::RenderVector>();
}

void Renderer::Tick(double dt) {
    auto window = GetState<component::Window>()->GetWindow();
    auto render_vector = GetState<component::RenderVector>();


    window->clear({150, 150, 150});
    sort(render_vector->begin(), render_vector->end());
    for (auto drawable: *render_vector) {
        drawable.second->Draw(window);
    }

    window->display();    
    render_vector->clear();
}

}
