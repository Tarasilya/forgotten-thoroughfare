#include "bc_visibility.h"

#include "component/attack.h"
#include "component/backpack.h"
#include "component/craft/craft.h"
#include "component/parent_entity.h"
#include "component/player.h"
#include "component/state/player_commands.h"
#include "component/text.h"
#include "component/transform.h"

#include <cmath>


namespace systems {

BCVisibility::BCVisibility(SystemManager* manager)
        : System(manager, "BCVisibility") {
    InitRequiredComponents();
    InitUsedState();
}


void BCVisibility::InitRequiredComponents() {
    AddRequiredComponent<component::Player>();
    AddRequiredComponent<component::Craft>();
    AddRequiredComponent<component::Backpack>();
}

void BCVisibility::InitUsedState() {
    AddUsedState<component::PlayerCommands>();
}

void BCVisibility::Tick(double dt) {
    auto player_commands = GetState<component::PlayerCommands>();
    for (auto entity: Entities()) {
        auto backpack = GetComponent<component::Backpack>(entity);
        auto craft = GetComponent<component::Craft>(entity);
        if (player_commands->Get(component::TOGGLE_CRAFT)) {
            ToggleEntity(craft, 
                entity, 
                component::Craft::CraftMenuString(craft, backpack));
            RemoveEntity(backpack);
        }
        if (player_commands->Get(component::TOGGLE_BACKPACK)) {
            ToggleEntity(backpack, entity, backpack->ToString());
            RemoveEntity(craft);            
        }
    }
}

void BCVisibility::ToggleEntity(HasEntity* parent, Entity* entity, std::string text) {
    if (parent->GetEntity() == 0) {
        parent->SetEntity(CreateTextEntity(entity, text));
    }
    else {
        RemoveEntity(parent);
    }
}

void BCVisibility::RemoveEntity(HasEntity* parent) {
    system_manager_->RemoveEntity(parent->GetEntity());
    parent->RemoveEntity();
}

Entity* BCVisibility::CreateTextEntity(Entity* parent, std::string content) {
    Entity* text = new Entity("bc_text");
    text->AddComponent(new component::Text(content));
    text->AddComponent(new component::Transform());
    text->AddComponent(new component::ParentEntity(parent));
    system_manager_->AddEntity(text);
    return text;
}

}
