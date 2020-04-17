#include "view.h"

#include "painter/painter.h"

View::View() {
    Painter::GetPainter()->AddView(this);
}

void View::SetZ(int z) {
    Painter::GetPainter()->RemoveView(this);
    z_ = z;
    Painter::GetPainter()->AddView(this);
}

int View::Z() {
    return z_;
}