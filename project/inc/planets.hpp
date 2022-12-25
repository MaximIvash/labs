#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>

namespace mi
{
    class Planets
    {
    public:
        Planets(int startx, int starty, int r, int v);
        Planets(int r, int v);
        int getx();
        int gety();
        void move(double s);
        void setPosition(int startx, int starty);
    private:
        int x0 = 0, y0 = 0, rad = 0, x = 0, y = 0, vector = 1;
        double a = 0;
        const double PI = acos(-1.0);
    };
    
}

