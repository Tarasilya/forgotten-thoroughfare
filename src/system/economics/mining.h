#pragma once

#include "system/system.h"

namespace systems {

class SystemManager;

class Mining: public System {
private:
	static const Aspect mining_aspect_;
	static const Aspect balance_aspect_;

protected:
    void InitUsedState() override;

public:
    Mining(SystemManager* manager);

    void Tick(double dt) override;
};

}
