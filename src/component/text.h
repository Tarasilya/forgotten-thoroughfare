#pragma once

#include "component.h"

#include <string>


namespace component {

class Text: public Component {
private:
    std::string text_; 
public:
    Text() = default;
    Text(std::string text);
    void SetText(std::string text);
    const std::string& GetText();
};

}
