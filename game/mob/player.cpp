#include "player.hpp"

Player::Player(def_rect ground) : ground(ground) {
    int x = SCREEN_WIDTH / 2;
    int y = 0;
    float vx, vy = 0;
    float vx = 0;
}

void Player::update() {
    if (collision.RectRect(x, y, PLAYER_WIDTH, Player_HEIGHT, Ground_x, Ground_y, Ground_width, Ground_height)) {
        vy = -(vy / BOUNCEREDUCTION);
        if (vy > -(BOUNCEREDUCTION)) {
            vy = 0;
        }
    } else {
        vy += GRAVITY;
        if (vy > TERMINAL_VELOCITY) {
            vy = TERMINAL_VELOCITY;
        }
    }
    y += vy;
    x += vx;
}

void Player::jump() {
    vy = -(TERMINAL_VELOCITY / 4)
}

void Player::moveLeft() {
    vx -= GRAVITY
}

void Player::moveRight() {
    vx += GRAVITY
}

int Player::getX() { return x; }
int Player::getY() { return y; }