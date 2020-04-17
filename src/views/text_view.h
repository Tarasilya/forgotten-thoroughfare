#pragma once

#include "view.h"

#include <SFML/Graphics.hpp>

class TextView : public View {
private:
    sf::Text text_;
public:
    TextView();
    TextView(const std::string& string);


	void SetText(const std::string& string);
	sf::Text* GetText();
	void SetCoords(double x, double y);
    void Draw(Painter* painter) override;

    void Draw(Painter* painter, double x, double y);
};