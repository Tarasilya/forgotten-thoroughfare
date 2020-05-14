#include "craft_select.h"

#include "component/backpack.h"
#include "component/craft/craft.h"
#include "component/player.h"
#include "component/state/player_commands.h"
#include "component/text.h"



namespace systems {

CraftSelect::CraftSelect(SystemManager* manager)
        : System(manager, "CraftSelect") {
    InitRequiredComponents();
    InitUsedState();
}


void CraftSelect::InitRequiredComponents() {
    AddRequiredComponent<component::Backpack>();
    AddRequiredComponent<component::Craft>();
    AddRequiredComponent<component::Player>();
}

void CraftSelect::InitUsedState() {
    AddUsedState<component::PlayerCommands>();
}

void CraftSelect::Tick(double dt) {
    auto player_commands = GetState<component::PlayerCommands>();
    for (auto entity: Entities()) {
        auto backpack = GetComponent<component::Backpack>(entity);
        auto craft = GetComponent<component::Craft>(entity);
        Entity* craft_view = craft->GetEntity();
        if (craft_view == 0) {
            continue;
        }
        if (player_commands->Get(component::MENU_DOWN)) {
            craft->SelectNext();
            craft_view
                ->GetComponent<component::Text>()
                ->SetText(component::Craft::CraftMenuString(craft, backpack));
        }
        if (player_commands->Get(component::MENU_UP)) {
            craft->SelectPrevious();
            craft_view
                ->GetComponent<component::Text>()
                ->SetText(component::Craft::CraftMenuString(craft, backpack));
        }
    }
}

}
