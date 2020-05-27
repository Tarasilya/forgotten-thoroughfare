#pragma once

#include "component.h"
#include "key_state.h"

namespace component {

class Mouse: public Component {
private:
    KeyState left_;
public:
    KeyState LeftState();
    void UpdateLeft(bool value);

};

}
