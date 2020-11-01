#pragma once

#include "component.h"

namespace component {

class Mine: public Component {
private:
    const double productivity_ = 0.1; 
public:
    double GetProductivity();
};

}
