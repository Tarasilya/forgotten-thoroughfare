/*
class Rectangle: public Component{

private:
    sf::Color color_;
    std::pair<double, double> size_;
    double thickness_;
    int layer_;

public:
    Rectangle(sf::Color color_, 
        double width_, 
        double height_,
        double thickness_,
        int layer = 0);
    
    std::pair<double, double> GetSize();
    double GetThickness();
    int GetLayer();
};
*/



#include "rectangle.h"


namespace component {

Rectangle::Rectangle(sf::Color color, 
				double width,
				double height,
				double thickness,
				int layer)
        : color_(color), size_({width, height}), 
        thickness_(thickness), layer_(layer) {}


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

}