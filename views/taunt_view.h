#pragma once

#include "texture_view.h"
#include "objects/taunt/taunt.h"

class TauntView : public TextureView {
private:
    Taunt* taunt_;
public:
    TauntView(Taunt* taunt, Painter* painter);
    void Draw(Painter* painter) override;
    bool GetVisibility();
};