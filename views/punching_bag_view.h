#pragma once

#include "texture_view.h"

class PunchingBag;

class PunchingBagView : public TextureView {
private:
    PunchingBag* bag_;
public:
    PunchingBagView(PunchingBag* bag);
    void Draw(Painter* painter) override;
};