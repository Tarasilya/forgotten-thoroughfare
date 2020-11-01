#include "mining.h"

#include "component/account_balance.h"
#include "component/text.h"
#include "component/mine.h"
#include "entity.h"

#include <iostream>
#include <cassert>

namespace systems {

const Aspect Mining::mining_aspect_
        = Aspect::CreateAspect<component::Mine>();

const Aspect Mining::balance_aspect_
        = Aspect::CreateAspect<component::AccountBalance, component::Text>();

Mining::Mining(SystemManager* manager)
        : System(manager, "Mining") {
    InitUsedState();
    manager->RegisterAspect(mining_aspect_);
    manager->RegisterAspect(balance_aspect_);
}

void Mining::InitUsedState() {
}

void Mining::Tick(double dt) {
    
    auto mine_entities = system_manager_->GetAspectEntities(mining_aspect_);
    auto balance_entities = system_manager_->GetAspectEntities(balance_aspect_);
    
    // We only expect there to be one balance entity
    assert(balance_entities.size() == 1);

    auto balance_entity = *balance_entities.begin();

    double total_productivity = 0;



    for (auto entity: mine_entities) {
        total_productivity += entity->GetComponent<component::Mine>()
                                    ->GetProductivity();
    }

    double total_earnings = total_productivity * dt;

    component::AccountBalance::ChangeMoney(balance_entity, total_earnings);
}

}
