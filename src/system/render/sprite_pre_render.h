#pragma once

#include "component/sprite.h"
#include "component/transform.h"
#include "system/system.h"


namespace systems {

class SystemManager;

class SpritePreRender: public System {
private:
    static const Aspect sprite_aspect_;
protected:
    void InitUsedState() override;

public:
    SpritePreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
