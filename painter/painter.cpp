#include "painter.h"

#include <SFML/Graphics.hpp>

#include <cmath>
#include <cstdio>
#include <iostream>
#include <cassert>

Painter* Painter::painter_ = 0;

const double ALLOWANCE = 0.4;

void Painter::Init(sf::RenderWindow* window) {
	painter_ = new Painter(window);
}

Painter::Painter(sf::RenderWindow* window) {
	display_rect_ = new RectCollisionBox(0, 0, 1, 1);

	window_ = window;

	display_width_ = window_->getSize().x;
	display_height_ = window_->getSize().y;

	if (!font_.loadFromFile("SEASRN__.ttf"))
	{
	    std::cerr << "cant load font!!" << std::endl;
	}	
}

Painter* Painter::GetPainter() {
	assert(painter_ != 0);
	return painter_;
}

void Painter::PlayerMoved(double x, double y) {
	if (x < display_rect_->x1 + ALLOWANCE) {
		display_rect_->Move(-(display_rect_->x1 + ALLOWANCE - x), 0);
	}
	if (y < display_rect_->y1 + ALLOWANCE) {
		display_rect_->Move(0, -(display_rect_->y1 + ALLOWANCE - y));
	}
	if (x > display_rect_->x2 - ALLOWANCE) {
		display_rect_->Move(x - (display_rect_->x2 - ALLOWANCE), 0);
	}
	if (y > display_rect_->y2 - ALLOWANCE) {
		display_rect_->Move(0, y - (display_rect_->y2 - ALLOWANCE));
	}
}

void Painter::Draw(const Rectangle& rect) {
	int x1 = Transform(rect.x1 - display_rect_->x1, display_width_);
	int y1 = Transform(rect.y1 - display_rect_->y1, display_height_);
	int x2 = Transform(rect.x2 - display_rect_->x1, display_width_);
	int y2 = Transform(rect.y2 - display_rect_->y1, display_height_);

	sf::ConvexShape draw_rect;

	draw_rect.setPointCount(4);
	draw_rect.setFillColor(rect.color.ToSf());
	draw_rect.setPoint(0, sf::Vector2f(x1, y1));
	draw_rect.setPoint(1, sf::Vector2f(x1, y2));
	draw_rect.setPoint(2, sf::Vector2f(x2, y2));
	draw_rect.setPoint(3, sf::Vector2f(x2, y1));

	window_->draw(draw_rect);
}

void Painter::Draw(const sf::Text& text, bool absolute) {
	sf::Vector2f coords = text.getPosition();
	float text_x = coords.x;
	float text_y = coords.y;
	int x = Transform(text_x - display_rect_->x1 * absolute, display_width_);
	int y = Transform(text_y - display_rect_->y1 * absolute, display_height_);
	sf::Text draw_text;
	draw_text.setString(text.getString());
	draw_text.setFont(font_);
	draw_text.setCharacterSize(50);
	draw_text.setPosition(sf::Vector2f(x, y));
	draw_text.setColor(sf::Color::White);
	window_->draw(draw_text);
}


void Painter::Draw(sf::Sprite* player_sprite){
	auto position = player_sprite->getPosition();
	player_sprite->setPosition(
		position.x - Transform(display_rect_->x1, display_width_),
		position.y - Transform(display_rect_->y1, display_width_)
	);
 	window_->draw(*player_sprite);
	player_sprite->setPosition(position);
}

void Painter::AddView(View* view) {
	views_.insert(view);
}

void Painter::RemoveView(View* view) {
	views_.erase(view);
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
	return round(coord * size);
}
