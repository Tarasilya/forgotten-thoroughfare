#pragma once

#include "component.h"

namespace component {

class Mine: public Component {
private:
    const int productivity_ = 10; 
public:
    int GetProductivity();
};

}
