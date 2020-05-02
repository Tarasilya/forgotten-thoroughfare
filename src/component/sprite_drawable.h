#pragma once

#include "component.h"

#include <string>

class SpriteDrawable: public Component{
private:
    std::string drawable_;
public:
    SpriteDrawable(const std::string& drawable);
    ~SpriteDrawable() override;
    
    const std::string& GetDrawable();
};