#include "controller.h"
#include "game.h"

#include "client/client.h"
#include "painter/painter.h"

#include <iostream>

void Controller::Run() {
    int size = sf::VideoMode::getDesktopMode().height * 0.9;
    window_ = new sf::RenderWindow(sf::VideoMode(size, size), "SYLA");

    Painter::Init(window_);
    Painter* painter = Painter::GetPainter();

    Game::StartGame();
    game_ = Game::GetGame();

    client_ = new Client();

    clock_t prev_t = clock();
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


        clock_t t = clock();
        double dt = (t - prev_t) * 1.0 / CLOCKS_PER_SEC;
        if ( dt > 0.016){
            prev_t = t;

            ProcessPressedKeys();
            std::vector<std::string> actions = client_->Receive();
            for (auto action : actions) {
                game_->ProcessAction(action);
            }
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
        std::string action = game_->ProcessKey(key, pressed, false);
        SendAction(action);
        pressed_keys_[key] = false;
    }    
    else {
        pressed_keys_.erase(key);
    }
}

void Controller::SendAction(const std::string& action) {
    if (action == "") {
        return;
    }
    client_->Send(action);
}

void Controller::ProcessPressedKeys() {
    for (auto it = pressed_keys_.begin(); it != pressed_keys_.end(); it++) {
       if (it->second) {
            std::string action = game_->ProcessKey(it->first, true, it->second);
            SendAction(action);
        }
        it->second = true;
    }
}