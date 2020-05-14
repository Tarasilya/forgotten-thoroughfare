#pragma once

#include "system/system.h"


namespace systems {

class SystemManager;

class PlayerMovement: public System {
private:
    void CreateAttack(Entity* entity);
protected:
    void InitRequiredComponents() override;
    void InitUsedState() override;

public:
    PlayerMovement(SystemManager* manager);

    void Tick(double dt) override;
};

}
