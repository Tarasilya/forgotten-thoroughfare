#pragma once

#include "system/system.h"
#include "component/transform.h"
#include "system/system.h"

namespace systems {

class SystemManager;

class RectanglePreRender: public System {
private:
	static const Aspect rectangle_aspect_;

protected:
    void InitUsedState() override;

public:
    RectanglePreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
