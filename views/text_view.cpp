#include "text_view.h"

#include "painter/painter.h"

#include <cstdio>
#include <iostream>
#include <stdlib.h>

TextView::TextView(const std::string& string) {
    text_.setString(string);
}

void TextView::Draw(Painter* painter) {
    painter->Draw(text_);
}

void TextView::Draw(Painter* painter, double x, double y) {
    SetCoords(x, y);
    painter->Draw(text_);
}

void TextView::SetText(const std::string& string) {
    text_.setString(string);
}

void TextView::SetCoords(double x, double y) {
    text_.setPosition(x, y);
}

sf::Text* TextView::GetText() {
    return &text_;
}

