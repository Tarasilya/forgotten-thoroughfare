#pragma once

#include "component.h"

#include <string>


namespace component {

class Sprite: public Component{
private:
    std::string drawable_;
    std::pair<double, double> size_;
    int layer_;
public:
    Sprite(const std::string& drawable, 
        double width, double height, int layer = 0);
    
    const std::string& GetDrawable();
    std::pair<double, double> GetSize();
    int GetLayer();
};

}
