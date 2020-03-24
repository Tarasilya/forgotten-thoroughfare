#include "player_view.h"
#include "view_factory.h"


View* ViewFactory::CreateView(Player* player, Painter* painter) {
    return new PlayerView(player, painter);
}