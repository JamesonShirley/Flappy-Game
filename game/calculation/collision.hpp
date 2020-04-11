#pragma once
class Collision {
   public:
    bool RectRect(int r1X, int r1Y, int r1W, int r1H, int r2X, int r2Y, int r2W, int r2H) { return r1X + r1W >= r2X && r1X <= r2X + r2W && r1Y + r1H >= r2Y && r1Y <= r2Y + r2H; }
};