#define OLC_PGE_APPLICATION
#include "DEFINITIONS.hpp"
#include "calculation/collision.hpp"
#include "mob/player.hpp"
#include "olcPixelGameEngine.hpp"

class game : public olc::PixelGameEngine {
   public:
    game() {
        sAppName = "temp";
    }

    bool OnUserCreate() override {
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
        Clear(olc::BLACK);

        //    if(GetKey(olc::A).bHeld){ player.moveLeft() }
        //   if(GetKey(olc::D).bHeld){ player.moveRight() }
        if (GetKey(olc::SPACE).bPressed) {
            vy = -(TERMINAL_VELOCITY * 3);
        } else {
            if (collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, 0, GROUND_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT)) {
                vy = 0;
            } else {
                vy = 4;
            }
        }

        if (pipe_x % 100 == 0 && pipe_x < -1) {
            pipe_x = x + 1000;
        }

        if (pipe_y % 100 == 0 && pipe_y < -1) {
            pipe_y = x + 1000;
        }

        if (pipe_z % 100 == 0 && pipe_z < -1) {
            pipe_z = x + 1000;
        }

        if (pipe_a % 100 == 0 && pipe_a < -1) {
            pipe_a = x + 1000;
        }

        FillRect(pipe_x, 0, PIPE_WIDTH, PIPE_HEIGHT, olc::RED);
        FillRect(pipe_x, (GROUND_HEIGHT - PIPE_HEIGHT), PIPE_WIDTH, PIPE_HEIGHT, olc::RED);

        FillRect(pipe_y, 0, PIPE_WIDTH, PIPE_HEIGHT - 75, olc::RED);
        FillRect(pipe_y, (GROUND_HEIGHT - PIPE_HEIGHT - 75), PIPE_WIDTH, PIPE_HEIGHT + 75, olc::RED);

        FillRect(pipe_a, 0, PIPE_WIDTH, PIPE_HEIGHT, olc::RED);
        FillRect(pipe_a, (GROUND_HEIGHT - PIPE_HEIGHT), PIPE_WIDTH, PIPE_HEIGHT, olc::RED);

        FillRect(pipe_z, 0, PIPE_WIDTH, PIPE_HEIGHT - 125, olc::RED);
        FillRect(pipe_z, (GROUND_HEIGHT - PIPE_HEIGHT - 125), PIPE_WIDTH, PIPE_HEIGHT + 125, olc::RED);

        if (collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_x, 0, PIPE_WIDTH, PIPE_HEIGHT) ||
            collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_y, 0, PIPE_WIDTH, PIPE_HEIGHT - 75) ||
            collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_z, 0, PIPE_WIDTH, PIPE_HEIGHT - 125) ||
            collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_a, 0, PIPE_WIDTH, PIPE_HEIGHT)) {
            xz = 0;
            if (vy < 0) {
                vy = 0;
            }

        }

        else if (collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_x, (GROUND_HEIGHT - PIPE_HEIGHT), PIPE_WIDTH, PIPE_HEIGHT) ||
                 collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_y, (GROUND_HEIGHT - PIPE_HEIGHT - 75), PIPE_WIDTH, PIPE_HEIGHT + 75) ||
                 collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_z, (GROUND_HEIGHT - PIPE_HEIGHT - 125), PIPE_WIDTH, PIPE_HEIGHT + 125) ||
                 collision.RectRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, pipe_a, (GROUND_HEIGHT - PIPE_HEIGHT), PIPE_WIDTH, PIPE_HEIGHT)) {
            xz = 0;
            if (vy > 0) {
                vy = 0;
            }
        }

        else {
            xz = 4;
        }

        y += vy;
        pipe_x -= xz;
        pipe_y -= xz;
        pipe_z -= xz;
        pipe_a -= xz;

        FillRect(x2, y, PLAYER_WIDTH, PLAYER_HEIGHT, olc::BLUE);
        FillRect(0, GROUND_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, olc::GREEN);
        return true;
    }

   private:
    Collision collision;
    int pipe_x = -100;
    int pipe_y = 200;
    int pipe_z = 800;
    int pipe_a = 500;
    int x = 0;
    int x2 = SCREEN_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2;
    float vy = 0;
    int xz = 0;
    int col_num = 0;
};
