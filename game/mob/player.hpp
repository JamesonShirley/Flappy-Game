#pragma once
#include "../DEFINITIONS.hpp"
#include "../calculation/collision.hpp"
class player {
   public:
    player();

    void update();

    void jump();
    void moveLeft();
    void moveRight();

   private:
    Collision collision;
    int x, y;
    float vx, vy;
};
