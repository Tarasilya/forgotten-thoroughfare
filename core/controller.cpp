#include "controller.h"
#include "game.h"

#include "painter/painter.h"

#include <iostream>

void Controller::Run() {
    window_ = new sf::RenderWindow(sf::VideoMode(1000, 1000), "SYLA");
    Painter::Init(window_);
    Painter* painter = Painter::GetPainter();
    Game::StartGame();
    game_ = Game::GetCurrentGame();

    clock_t t = clock();
    clock_t prev_t = t;
    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window_->close();
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    ProcessKey(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    ProcessKey(event.key.code, false);
                    break;
            }
        }


        clock_t dt = clock() - t;
        t = clock();
        if ( ((t - prev_t) * 1.0) / CLOCKS_PER_SEC > 0.016){
            prev_t = t;

            ProcessPressedKeys();
            game_->Tick(dt);
            painter->Redraw();
            window_->display();
        }
    }
}

void Controller::ProcessKey(sf::Keyboard::Key key, bool pressed) {
    if (key == sf::Keyboard::Escape) {
        window_->close();
        exit(0);
    }
    
    if (pressed) {
        game_->ProcessKey(key, pressed, false);
        pressed_keys_[key] = false;
    }    
    else {
        pressed_keys_.erase(key);
    }
}

void Controller::ProcessPressedKeys() {
    for (auto it = pressed_keys_.begin(); it != pressed_keys_.end(); it++) {
        std::cerr << "PressedKeys: " << it->first << " " << it->second << " " << pressed_keys_.size() << std::endl;
        if (it->second) {
            game_->ProcessKey(it->first, true, it->second);
        }
        it->second = true;
    }
}