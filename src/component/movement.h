#pragma once

#include "component.h"


namespace component {

class Movement: public Component {
private:
    double dx_;
    double dy_;
public:
    Movement(double dx, double dy);

    double GetDx();
    double GetDy();

    void Set(double dx, double dy);
    void SetDx(double dx);
    void SetDy(double dy);
};

}
