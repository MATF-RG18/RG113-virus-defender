#include "GameVariables.hpp"
#include<iostream>
namespace vd {
    RandomReal GameVariables::rand_active_interval(10, 50);
    RandomReal GameVariables::rand_sleep_interval(15, 60);

    RandomReal GameVariables::rand_spawn_interval(3, 10);

    long long GameVariables::PLASMA = 0;
    GLfloat GameVariables::PORTAL_HP = 100000;
    int GameVariables::MANA = 0;
    Window GameVariables::window{GameVariables::INIT_WINDOW_WIDTH, GameVariables::INIT_WINDOW_HEIGHT};


    void GameVariables::update() {
        if (GameVariables::MANA < GameVariables::MAX_MANA) {
            GameVariables::MANA += GameVariables::MANA_REFRESH_RATE;
        }
    }
}
