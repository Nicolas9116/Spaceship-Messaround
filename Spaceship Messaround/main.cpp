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
            //MOVEMENT OVER===cpntinue polling other events

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                std::cout << "Spacebar pressed" << std::endl;
                Bullet b;
                b.GetBulletSprite().setPosition(player.GetSprite().getPosition());
                bullets.push_back(b);
            }
        }
        //=================DO THINGS====================

        for (auto& bullet : bullets)
        {      
            std::cout << "position of bullet" << 
                bullet.GetBulletSprite().getPosition().x <<
                " , " <<
                bullet.GetBulletSprite().getPosition().y << std::endl;

            bullet.GetBulletSprite().move(bullet.GetSpeed(), 0);
        }




        window.clear();//clear the previous frame before rendering a new frame

        //=================DRAW THINGS==================
        window.draw(player.GetSprite());
        
        for (auto& bullet : bullets)
        {
            window.draw(bullet.GetBulletSprite());
        }
        std::cout << "number of bullets being drawn" << bullets.size() << std::endl;
        //=================WRITE THE DRAW BUFFER AS A FRAME===============
        window.display();
    }

    return 0;
}