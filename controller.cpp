#include "controller.h"
#include "game.h"

#include "painter.h"

#include <iostream>

void Controller::Run() {
    window_ = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SYLA");
    Painter* painter = new Painter(window_);
    game_ = new Game(painter);

    double t = clock();
    double prev_t = t;
    int frame_ctr = 0;
    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window_->close();
                break;
            }

            if (event.type == sf::Event::KeyPressed) {
                ProcessKey(event.key.code);
            }
        }
        clock_t dt = clock() - t;
        t = clock();
        if ( ((t - prev_t) * 1.0) / CLOCKS_PER_SEC > 0.016){
            frame_ctr++;
            double start_mvt = t;
            prev_t = t;

            game_->Tick(dt);
            window_->clear({76, 180, 115});
            game_->Draw();
            window_->display();
        }
    }
}

void Controller::ProcessKey(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Escape) {
        window_->close();
        exit(0);
    }
    else {
        game_->ProcessKey(key);
    }
}
