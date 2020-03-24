#pragma once

#include "shapes.h"

#include <SFML/Graphics.hpp>

#include <utility>

const Color micro_MVP_RECTANGLE_COLOR = {82, 194, 228};

class Painter {
private:
	sf::RenderWindow* window_;
	int display_width_;
	int display_height_;

public:
	Painter(sf::RenderWindow* window);
	void Draw(const Rectangle& rect);
    void Draw(sf::Sprite* player_sprite);

	virtual int Width();
	virtual int Height();
    int Transform(double coord, int size);
};
