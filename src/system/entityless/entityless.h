#pragma once

#include "system/system.h"

namespace systems {

class Entityless: public System {
protected:
    const std::set<Entity*>& Entities() override;

    void InitRequiredComponents() override;
public:
    Entityless(SystemManager* manager, const std::string& name);
    void TryAddEntity(Entity* entity) override;
};

}
