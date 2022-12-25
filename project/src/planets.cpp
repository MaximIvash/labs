#include <math.h>
#include <SFML/Graphics.hpp>
#include "planets.hpp"

namespace mi 
{
    Planets::Planets(int startx, int starty, int r, int v)
    {
        if (v > 1)
            v = 1;
        if (v < 1 || v == 0)
            v = -1;
        vector = v;
        x0 = startx;
        y0 = starty;
        rad = r;
    }
    Planets::Planets(int r, int v)
    {
        if (v > 1) v = 1;
        if (v < -1 || v == 0)v = -1;
        vector = v;
        rad = r;
    }
    int Planets::getx()
    {
        return x;
    }
    int Planets::gety()
    {
        return y;
    }
    void Planets::move(double s)
    {
        a += s;
        if (a > 360)
            a = 0;
        x = x0 + round(rad * cos(a * PI / 180));
        y = y0 + round(rad * sin(a * PI / 180)) * vector;

    }
    void Planets::setPosition(int startx, int starty)
    {
        x0 = startx;
        y0 = starty;
    }
}


