#pragma once 

#include "component/component.h"

#include <vector>


class Drawable;

namespace component {

class RenderVector: public std::vector<std::pair<int, Drawable*>>, 
                    public Component {
};

}
