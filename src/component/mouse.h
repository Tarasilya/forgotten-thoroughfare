#pragma once

#include "component.h"


namespace component {

class Mouse: public Component {
private:
    bool left_pressed_ = false;
public:
    bool IsLeftPressed();
    void SetLeftPressed(bool value);
};

}
