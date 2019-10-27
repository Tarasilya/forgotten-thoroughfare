#include "rat_view.h"
#include "view_factory.h"


View* ViewFactory::CreateView(Rat* rat, Painter* painter) {
    return new RatView(rat, painter);
}