#pragma once

#include "texture_view.h"

class Item;

class ItemView : public TextureView {
private:
    Item* item_;
public:
    ItemView(Item* item, Painter* painter);
    void Draw(Painter* painter) override;
    bool GetVisibility();
};