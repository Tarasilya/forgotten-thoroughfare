#include "text.h"


namespace component {

Text::Text(std::string text): text_(text) {}

void Text::SetText(std::string text) {
    text_ = text;
}

const std::string& Text::GetText() {
    return text_;
}

}
