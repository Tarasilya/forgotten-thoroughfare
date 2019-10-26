#include "game.h"
#include "player.h"
#include "view.h"

#include "painter.h"

#include <iostream>
#include <cmath>
#include <sstream>

Game::Game(Painter* painter) {
    painter_ = painter;
    View* view = new View(0.5, 0.5);
    players_.push_back(new Player(view));
    views_.push_back(view);
}

void Game::Draw() {
    for (auto view: views_) {
        view->Draw(painter_);
    }
}

void Game::ProcessKey(sf::Keyboard::Key key)
{
    for (auto player : players_) {
        if (player->ProcessKey(key)) {
            break;
        }
    }
}

void Game::Tick(double dt)
{
}
