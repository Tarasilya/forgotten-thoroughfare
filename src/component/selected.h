#pragma once

#include "component.h"

#include <chrono>


namespace component {

class Selected: public Component {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> when_;
public:
    Selected();

    std::chrono::time_point<std::chrono::high_resolution_clock> When();
};

}
