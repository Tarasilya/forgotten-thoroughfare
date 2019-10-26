#pragma once

#include <SFML/Graphics.hpp>

#include <string>

struct Color {
	int r;
	int g;
	int b;
	int a;
	Color();
	Color(int r, int g, int b);
	Color(int r, int g, int b, int a);
	sf::Color ToSf() const;
};

struct Rectangle {
	double x1;
	double y1;
	double x2;
	double y2;
	Color color;
};


