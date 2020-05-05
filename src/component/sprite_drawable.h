#pragma once

#include "component.h"

#include <string>


namespace component {

class SpriteDrawable: public Component{
private:
    std::string drawable_;
public:
    SpriteDrawable(const std::string& drawable);
    
    const std::string& GetDrawable();
};

}
