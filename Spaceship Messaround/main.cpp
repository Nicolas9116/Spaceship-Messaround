#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>   

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>

#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

std::pair<int, int> GenerateRandomEnemySpawn();

void SpawnEnemy(sf::Texture& texture);

std::vector<Bullet> bullets;
std::vector<Enemy> enemies;

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	//========Load Textures=============
	sf::Texture playerTex;
	playerTex.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/player_ship.png");

	sf::Texture bulletTex;
	bulletTex.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/blue_lazer.png");

	sf::Texture enemyTex;
	enemyTex.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/enemy_ship.png");
	//========End Load Textures=========

	sf::RenderWindow window(sf::VideoMode(1280, 1080), "SFML works!");
	window.setFramerateLimit(60);

	Player player(playerTex);

	sf::Clock clock;
	//========Main Game Loop============
	while (window.isOpen())
	{

		player.ResetAcceleration();

		//========POLL EVENTS===============
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				std::cout << "Spacebar pressed" << std::endl;
				Bullet b(bulletTex);
				b.GetBulletSprite().setPosition(player.GetSprite().getPosition());
				bullets.push_back(b);
			}
		}
			//MOVEMENT

		int airResistanceDetection = 0;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				std::cout << "A key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(-1, 0));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				std::cout << "D key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(1, 0));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				std::cout << "W key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(0, -1));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				std::cout << "S key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(0, 1));
				airResistanceDetection++;
			}

			//'AIR RESISTANCE' to come to a stop when no directions are pressed
			if (airResistanceDetection == 0)//checks if there was a directional keypress in this frame, IFNOT slow down
			{
				player.ApplyAirResistance();
			}
			// If either axis has no inputs, decelerate that axis independantly->avoids the case of pressing W+A and then releasing A but maintaining the W axis of movement
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player.ResetVerticalVelocity();
			}
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.ResetHorizontalVelocity();
			}

			//MOVEMENT OVER=============================


			std::cout << "Player Velocity: (" << player.GetVelocity().x << ", " << player.GetVelocity().y << ")" << std::endl;

		//=================DO THINGS====================
		
		float elapsedTime = clock.getElapsedTime().asSeconds();

		player.UpdateVelocity(player.GetAcceleration());
		player.GetSprite().move(player.GetVelocity());

		if (elapsedTime > 3)//every three seconds add another enemy to the scene
		{
			std::cout << "enemy spawn called" << std::endl;
			SpawnEnemy(enemyTex);
			clock.restart();
		}
		
		for (auto& bullet : bullets)//Move bullet
		{
			bullet.GetBulletSprite().move(bullet.GetSpeed(), 0);
		}


		//=================CLEAR PREVIOUS FRAME=========

		window.clear();//clear the previous frame before rendering a new frame

		//=================CLEARED PREVIOUS FRAME=======
		
		
		//=================DRAW THINGS==================
		window.draw(player.GetSprite());

		for (auto& bullet : bullets)
		{
			window.draw(bullet.GetBulletSprite());
		}

		for (auto& enemies : enemies)
		{
			window.draw(enemies.GetEnemySprite());
		}
		//std::cout << "number of bullets being drawn" << bullets.size() << std::endl;
		//=================FINISH DRAW==================


		//=================WRITE THE DRAW BUFFER AS A FRAME===============
		window.display();
	}
	return 0;


}

std::pair<int, int> GenerateRandomEnemySpawn()
{
	// Define the x range (e.g., [100, 200])
	int x_min = 900;
	int x_max = 1280;

	// Define the y range (e.g., [0, 1080])
	int y_min = 0;
	int y_max = 1080;

	// Generate a random x position within the range [x_min, x_max]
	int random_x = x_min + std::rand() % (x_max - x_min + 1);

	// Generate a random y position within the range [y_min, y_max]
	int random_y = y_min + std::rand() % (y_max - y_min + 1);

	return std::make_pair(random_x, random_y);
}

void SpawnEnemy(sf::Texture& texture)
{
	Enemy enemyShip(texture);
	auto position = GenerateRandomEnemySpawn();
	enemyShip.GetEnemySprite().setPosition(position.first, position.second);
	enemies.push_back(enemyShip);
	std::cout << "enemies in vector" << enemies.size() << std::endl;

}