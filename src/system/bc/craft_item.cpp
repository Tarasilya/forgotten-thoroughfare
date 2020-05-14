#include "craft_item.h"

#include "component/backpack.h"
#include "component/craft/craft.h"
#include "component/player.h"
#include "component/state/player_commands.h"
#include "component/text.h"



namespace systems {

CraftItem::CraftItem(SystemManager* manager)
        : System(manager, "CraftItem") {
    InitRequiredComponents();
    InitUsedState();
}


void CraftItem::InitRequiredComponents() {
    AddRequiredComponent<component::Backpack>();
    AddRequiredComponent<component::Craft>();
    AddRequiredComponent<component::Player>();
}

void CraftItem::InitUsedState() {
    AddUsedState<component::PlayerCommands>();
}

void CraftItem::Tick(double dt) {
    auto player_commands = GetState<component::PlayerCommands>();
    for (auto entity: Entities()) {
        auto backpack = GetComponent<component::Backpack>(entity);
        auto craft = GetComponent<component::Craft>(entity);
        Entity* craft_view = craft->GetEntity();
        if (craft_view == 0) {
            continue;
        }
        if (player_commands->Get(component::CRAFT)) {
            auto crafting_item = craft->GetSelected();
            auto recipe = craft->GetRecipe(crafting_item);
            if (recipe.IsEnough(backpack->GetItems())) {
                for (auto const& [item, count]: recipe.Get()) {
                    backpack->RemoveItem(item, count);
                }
                backpack->AddItem(crafting_item);
                craft->UpdateView(backpack);
            }
        }
    }
}

}
