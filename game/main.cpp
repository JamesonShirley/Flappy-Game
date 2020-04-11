#include "game.hpp"

int main() {
    game demo;
    if (demo.Construct(SCREEN_WIDTH, SCREEN_HEIGHT, SCALE_X, SCALE_Y)) {
        demo.Start();
    }
    return 0;
}
