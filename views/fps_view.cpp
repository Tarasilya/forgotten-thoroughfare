#include "fps_view.h"

#include "painter/painter.h"

const double X = 0;
const double Y = 0;


FpsView::FpsView() {
    SetZ(100);
    time_sum_ = 0;
    prev_draw_ = 0;
}

void FpsView::Draw(Painter* painter) {
    if (prev_draw_ != 0) {
        clock_t t = clock();
        draw_times_.push_back(t - prev_draw_);
        time_sum_ += t - prev_draw_;
        prev_draw_ = t;

        if (draw_times_.size() > BUFFER_SIZE) {
            time_sum_ -= draw_times_.front();
            draw_times_.pop_front();
        }
        int fps =  draw_times_.size() / (time_sum_ * 1.0 / CLOCKS_PER_SEC);

        SetText(std::to_string(fps) + " FPS");

        SetCoords(X, Y);
        painter->Draw(*GetText(), false);
    }
    prev_draw_ = clock();
}

