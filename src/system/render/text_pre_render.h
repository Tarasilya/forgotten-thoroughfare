#pragma once

#include "component/text.h"
#include "component/transform.h"
#include "system/system.h"

#include <SFML/Graphics.hpp>


namespace systems {

class SystemManager;

class TextPreRender: public System {
private:
    sf::Font font_;
    static const Aspect text_aspect_;

protected:
    void InitUsedState() override;

public:
    TextPreRender(SystemManager* manager);

    void Tick(double dt) override;
};

}
