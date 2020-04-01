#pragma once

#include "view.h"
#include "views/text_view.h"

#include <SFML/Graphics.hpp>

#include <deque>


const int BUFFER_SIZE = 1000;

class FpsView : public TextView {
private:
    std::deque<int> draw_times_;
    int time_sum_;
    clock_t prev_draw_; 
public:
    FpsView();
    void Draw(Painter* painter) override;
};