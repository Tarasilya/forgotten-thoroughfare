#pragma once

#include "shapes.h"

#include "collisions/rect_collision_box.h"
#include "views/view.h"

#include <SFML/Graphics.hpp>


#include <set>
#include <utility>
#include <functional>

const Color micro_MVP_RECTANGLE_COLOR = {82, 194, 228};

class Painter {
private:
    static Painter* painter_;
    Painter(sf::RenderWindow* window);

    RectCollisionBox* display_rect_;

	sf::RenderWindow* window_;
	int display_width_;
	int display_height_;
	sf::Font font_;

    //std::function<bool (int, int)> comp = 
    std::set<View*, std::function<bool (View*, View*m)>> views_ = 
        std::set<View*, std::function<bool (View*, View*)>>(
            [](View* a, View* b){ 
                if (a->Z() != b->Z()) {
                    return a->Z() < b->Z(); 
                }
                else {
                    return a < b;
                }
            });

public:
    static void Init(sf::RenderWindow* window);
    static Painter* GetPainter();

    void Redraw();
	void Draw(const Rectangle& rect);
	void Draw(const sf::Text& text);
    void Draw(sf::Sprite* player_sprite);

    void AddView(View* view);

    void PlayerMoved(double x, double y);

	virtual int Width();
	virtual int Height();
    int Transform(double coord, int size);
};
