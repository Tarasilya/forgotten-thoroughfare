#pragma once

#include "objects/items/stick/stick.h"
#include "views/item_view.h"

class StickView : public ItemView {
private:
    Stick* stick_;
public:
    StickView(Stick* stick, Painter* painter);
};