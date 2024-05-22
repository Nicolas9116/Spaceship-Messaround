#include <iostream>
#include <string>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.hpp"
#include "Bullet.hpp"

int main()
{
    Player player;


    sf::RenderWindow window(sf::VideoMode(1280, 1080), "SFML works!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::vector<Bullet> bullets;

    while (window.isOpen())
    {
//========POLL EVENTS===============
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            //MOVEMENT
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
            {
                std::cout << "A key pressed" << std::endl;
                player.GetSprite().move(-10, 0);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D))
            {
                std::cout << "D key pressed" << std::endl;
                player.GetSprite().move(10, 0);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
            {
                std::cout << "W key pressed" << std::endl;
                player.GetSprite().move(0, -10);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S))
            {
                std::cout << "S key pressed" << std::endl;
                player.GetSprite().move(0, 10);
            }
            //MOVEMENT OVER

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                std::cout << "Spacebar pressed" << std::endl;
                Bullet b = Bullet();
                Bullet& c = b;
                b.GetBulletSprite().setPosition(player.GetSprite().getPosition());
                bullets.push_back(c);
            }
        }
        //=================DO THINGS====================

        for (int i = 0; i < bullets.size(); i++)
        {
            Bullet& b = bullets[i];

            std::cout << "position of bullet" << 
                b.GetBulletSprite().getPosition().x <<
                " , " <<
                b.GetBulletSprite().getPosition().y << std::endl;

            b.GetBulletSprite().move(b.GetSpeed(), 0);
        }




        window.clear();//clear the previous frame before rendering a new frame

        //=================DRAW THINGS==================
        window.draw(player.GetSprite());
        
        for (int i = 0; i < bullets.size(); i++)
        {
            Bullet& b = bullets[i];

            window.draw(b.GetBulletSprite());
        }
        //=================WRITE THE DRAW BUFFER AS A FRAME===============
        window.display();
    }

    return 0;
}