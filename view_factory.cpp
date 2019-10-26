#include "rat_view.h"
#include "view_factory.h"


View* ViewFactory::CreateView(Rat* rat) {
    return new RatView(rat);
}