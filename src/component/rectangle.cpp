#include "rectangle.h"


namespace component {

Rectangle::Rectangle(double width, 
            double height,
            sf::Color color,
            int layer,
            double thickness,
            sf::Color outline_color)
        : size_({width, height}), color_(color), layer_(layer),
        thickness_(thickness), outline_color_(outline_color) {}


std::pair<double, double> Rectangle::GetSize() {
    return size_;
}

double Rectangle::GetThickness() {
	return thickness_;
}

int Rectangle::GetLayer() {
    return layer_;
}

sf::Color Rectangle::GetColor() {
    return color_;
}

sf::Color Rectangle::GetOutlineColor() {
    return outline_color_;
}

void Rectangle::SetWidth(double width) {
    size_.first = width;
}

}
