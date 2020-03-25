#include "painter.h"

#include <SFML/Graphics.hpp>

#include <cmath>
#include <iostream>

Painter* Painter::painter_ = 0;

void Painter::Init(sf::RenderWindow* window) {
	painter_ = new Painter(window);
}

Painter::Painter(sf::RenderWindow* window) {
	window_ = window;

	display_width_ = window_->getSize().x;
	display_height_ = window_->getSize().y;
}

Painter* Painter::GetPainter() {
	assert(painter_ != 0);
	return painter_;
}

void Painter::Draw(const Rectangle& rect) {
	int x1 = Transform(rect.x1, display_width_);
	int y1 = Transform(rect.y1, display_height_);
	int x2 = Transform(rect.x2, display_width_);
	int y2 = Transform(rect.y2, display_height_);

	sf::ConvexShape draw_rect;

	draw_rect.setPointCount(4);
	draw_rect.setFillColor(rect.color.ToSf());
	draw_rect.setPoint(0, sf::Vector2f(x1, y1));
	draw_rect.setPoint(1, sf::Vector2f(x1, y2));
	draw_rect.setPoint(2, sf::Vector2f(x2, y2));
	draw_rect.setPoint(3, sf::Vector2f(x2, y1));

	window_->draw(draw_rect);
}

void Painter::Draw(sf::Sprite* player_sprite){
  window_->draw(*player_sprite);
}

void Painter::AddView(View* view) {
	views_.insert(view);
}

void Painter::Redraw() {
	for (auto view : views_) {
        view->Draw(painter_);
    }

}

int Painter::Width() {
	return display_width_;
}

int Painter::Height() {
	return display_height_;
}

int Painter::Transform(double coord, int size) {
	return coord * size;
}
