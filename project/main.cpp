#include <SFML/Graphics.hpp>
#include <math.h>
#include "planets.hpp"
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1500, 1000), "Solar system", Style::Default);
    window.setVerticalSyncEnabled(true);

    vector<CircleShape> planets;
    vector <int> sizes = { 100,4,8,10,9,16,12,3 };
    vector <double> moves = { 0, 0.5, 0.25,0.18, 0.06, 0.03, 0.015, 0.7 };
    vector <double> rotations = { -0.03 ,0.5,0.3,0.6 ,0.5 ,0.1 ,0,0.01 };
    vector <string> file_names = { "sun.png", "merk.png", "venus.png" , "earth.png" ,"mars.png","jupiter.png","saturn.png","moon.png" };
    for (int i = 0; i < sizes.size(); i++)
    {
        planets.push_back(sf::CircleShape(sizes[i]));
    }
    vector<Texture> texts;
    for (int i = 0; i < planets.size(); i++)
    {
        Texture text;
        text.loadFromFile(file_names[i]);
        texts.push_back(text);
    }
    for (int i = 0; i < planets.size(); i++)
    {
        planets[i].setTexture(&texts[i]);
        planets[i].setOrigin(sizes[i], sizes[i]);
    }
    planets[0].setPosition(750, 500);
    planets[6].setScale(1.25f, 1.f);//фикс сатурна

    VertexArray stars(Points, 200);//звезды
    for (int i = 0; i < 200; i++)
    {
        stars[i].color = Color(255, 255, 255);
        stars[i].position = Vector2f(rand() % 1500, rand() % 1000);
    }

    vector <mi::Planets> Object = { mi::Planets(750, 500, 0, -1), mi::Planets(750, 500, 150, -1), mi::Planets(750, 500, 200, -1), mi::Planets(750, 500, 250, -1), mi::Planets(750, 500, 300, -1), mi::Planets(750, 500, 350, -1), mi::Planets(750, 500, 430, -1), mi::Planets(30, -1) };

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }


            for (int i = 1; i < planets.size();i++)
            {
                Object[i].move(moves[i]);
                planets[i].setPosition(Object[i].getx(), Object[i].gety());
                planets[i].rotate(rotations[i]);
            }
            planets[0].rotate(rotations[0]);//вращение солнца
            Object[7].setPosition(planets[3].getPosition().x, planets[3].getPosition().y);//луна
            Object[7].move(moves[7]);
            planets[7].rotate(rotations[7]);
            planets[7].setPosition(Object[7].getx(), Object[7].gety());

            window.clear();
            window.draw(stars);
            for (int i = 0; i < planets.size();i++)
            {
                window.draw(planets[i]);
                
            }
            window.display();
        }
    return 0;
}