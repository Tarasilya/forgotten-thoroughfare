#pragma once

class Rat;
class View;

class ViewFactory {
public:
    static View* CreateView(Rat* rat);
};