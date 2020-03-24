#pragma once

class Player;
class View;

class ViewFactory {
public:
    static View* CreateView(Player* player, Painter* painter);
};