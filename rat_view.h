#pragma once

#include "texture_view.h"

class Rat;

class RatView : public TextureView {
private:
    Rat* rat_;
public:
    RatView(Rat* rat, Painter* painter);
    void Draw(Painter* painter) override;
};