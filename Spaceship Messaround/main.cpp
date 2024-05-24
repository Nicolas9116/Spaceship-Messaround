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
#include "GUI.hpp"

enum class GameState
{
	Playing,
	GameOver
};

std::pair<int, int> GenerateRandomEnemySpawn();
void SpawnEnemy(sf::Texture& texture);
void UpdateFrameRate(sf::Clock& clock, GUI& gui);

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
	int bulletCounter = 0;//counter that drives the cooldown
	int bulletCoolDown = 10;//the cooldown period--higher number here is longer cooldown. At 60 FPS, 20 would result in 3 of x per second. IE CoolDown is expressed in frames.

	int dodgeTimer = 180;
	int dodgeCooldown = 180;

	int explosionTimer = 15;
	int explosionlength = 15;

	sf::RenderWindow window(sf::VideoMode(1280, 1080), "SFML works!");
	window.setFramerateLimit(60);

	Player player(playerTex);
	GUI gui;
	sf::Clock clock;
	sf::Clock frameRateClock;
	GameState gameState = GameState::Playing;

	//========Main Game Loop============
	while (window.isOpen())
	{
		bulletCounter++;
		
		if (explosionTimer < explosionlength)
		{
			explosionTimer++;
		}

		if (dodgeTimer < dodgeCooldown)
		{
			dodgeTimer++;
		}


		std::cout << dodgeTimer << std::endl;

		UpdateFrameRate(frameRateClock, gui);

		//========POLL EVENTS===============
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if ((sf::Mouse::isButtonPressed(sf::Mouse::Left) && bulletCounter > bulletCoolDown))
			{
				std::cout << "Spacebar pressed" << std::endl;
				Bullet b(bulletTex);
				b.GetBulletSprite().setPosition(player.GetSprite().getPosition());
				bullets.push_back(b);
				bulletCounter = 0;
			}
		}
		//MOVEMENT=================================

		if (gameState == GameState::Playing)
		{
			int airResistanceDetection = 0;
			player.ResetAcceleration();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				//std::cout << "A key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(-player.GetAccelerationForce(), 0));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				//std::cout << "D key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(player.GetAccelerationForce(), 0));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				//std::cout << "W key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(0, -player.GetAccelerationForce()));
				airResistanceDetection++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				//std::cout << "S key pressed" << std::endl;
				player.UpdateAcceleration(sf::Vector2f(0, player.GetAccelerationForce()));
				airResistanceDetection++;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && player.GetBombCharge() == 100)
			{
				for (auto enemy = enemies.begin(); enemy != enemies.end();)
				{
					enemy = enemies.erase(enemy);
				}
				player.ResetBombCharge();
				explosionTimer = 0;
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && dodgeTimer == dodgeCooldown)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					player.GetSprite().move(0, -200);
					dodgeTimer = 0;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					player.GetSprite().move(0, +200);
					dodgeTimer = 0;
				}
			}

			//MOVEMENT OVER=============================


		//=================DO THINGS====================

			float elapsedTime = clock.getElapsedTime().asSeconds();

			player.UpdateVelocity(player.GetAcceleration());
			player.GetSprite().move(player.GetVelocity());

			//Bounding Box for Player===================
			if (player.GetSprite().getPosition().x > window.getSize().x - player.GetSprite().getGlobalBounds().width / 2)//right check
			{
				player.GetSprite().setPosition(window.getSize().x - (player.GetSprite().getGlobalBounds().width / 2), player.GetSprite().getPosition().y);
			}
			if (player.GetSprite().getPosition().x < 0 + player.GetSprite().getGlobalBounds().width / 2)//left check
			{
				player.GetSprite().setPosition(0 + player.GetSprite().getGlobalBounds().width / 2, player.GetSprite().getPosition().y);
			}
			if (player.GetSprite().getPosition().y < 80 + player.GetSprite().getGlobalBounds().height / 2)//top check
			{
				player.GetSprite().setPosition(player.GetSprite().getPosition().x, 80 + player.GetSprite().getGlobalBounds().height / 2);
			}
			if (player.GetSprite().getPosition().y > 980 - player.GetSprite().getGlobalBounds().height / 2)//bottom check
			{
				player.GetSprite().setPosition(player.GetSprite().getPosition().x, 980 - player.GetSprite().getGlobalBounds().height / 2);
			}
			//Bounding Box END==========================

			if (elapsedTime > .75 && explosionTimer == explosionlength)//every three seconds add another enemy to the scene
			{
				std::cout << "enemy spawn called" << std::endl;
				SpawnEnemy(enemyTex);
				clock.restart();
			}

			//Iterate through the bullet
			//update their position by their speed.
			//For each bullet, check through the enemies for collisions
			//If colliding with an enemy, destroy both and break to the outer loop
			//check for out of bounds, then iterate.
			for (auto bullet = bullets.begin(); bullet != bullets.end(); )
			{
				bullet->GetBulletSprite().move(bullet->GetSpeed(), 0);

				bool bulletErased = false;

				for (auto enemy = enemies.begin(); enemy != enemies.end();)
				{
					if (bullet->GetBulletSprite().getGlobalBounds().intersects(enemy->GetEnemySprite().getGlobalBounds()))
					{
						enemy->TakeDamage(1);

						if (enemy->GetEnemyHealth() <= 0)
						{
							enemy = enemies.erase(enemy);
						}

						bullet = bullets.erase(bullet);
						bulletErased = true;
						player.UpdateScore(1);

							if (player.GetBombCharge() < 100)
							{
								player.UpdateBombCharge(10);
							}

						break; // Exit the inner loop
					}
					else
					{
						++enemy;
					}
				}

				if (bulletErased) continue; // If bullet was erased, skip to the next iteration of the outer loop

				if (bullet->GetBulletSprite().getPosition().x > 1290)
				{
					bullet = bullets.erase(bullet);
				}
				else
				{
					++bullet; // Move to the next bullet
				}
			}
			//Enemies are pretty much just bullets moving in the other direction. #poetry
			for (auto enemy = enemies.begin(); enemy != enemies.end();)
			{
				enemy->GetEnemySprite().move(enemy->GetSpeed() * -1, 0);
				enemy->UpdateEnemyHealthBar();
				enemy->GetEnemyHealthBar().move(enemy->GetSpeed() * -1, 0);

				if (enemy->GetEnemySprite().getGlobalBounds().intersects(player.GetSprite().getGlobalBounds()))
				{
					enemy = enemies.erase(enemy);
					player.TakeDamage(1);
					std::cout << "Player Health " << player.GetHealth() << std::endl;
				}

				else if (enemy->GetEnemySprite().getPosition().x < -10)
				{
					enemy = enemies.erase(enemy);
				}
				else
				{
					++enemy;
				}
			}

			//=================UPDATE GUI=================
			gui.UpdateScore(player.GetScore());
			gui.UpdateHealthBar(player.GetHealth());
			gui.UpdateDashBar(dodgeTimer);
			gui.UpdateBombBar(player.GetBombCharge());
			//=================CLEAR PREVIOUS FRAME=========

			window.clear();//clear the previous frame before rendering a new frame

			//=================CLEARED PREVIOUS FRAME=======

			//=================DRAW THINGS==================
			window.draw(player.GetSprite());

			window.draw(gui.GetScoreText());
			window.draw(gui.GetHealthBarBacking());
			window.draw(gui.GetHealthBar());
			window.draw(gui.GetDashBar());
			window.draw(gui.GetDashBarBacking());
			window.draw(gui.GetFrameRateText());
			window.draw(gui.GetBombBar());
			window.draw(gui.GetBombBarBacking());

			if (explosionTimer < explosionlength)
			{
				window.draw(gui.GetExplosion());
			}

			for (auto& bullet : bullets)
			{
				window.draw(bullet.GetBulletSprite());
			}

			for (auto& enemies : enemies)
			{
				window.draw(enemies.GetEnemySprite());
				window.draw(enemies.GetEnemyHealthBar());
				std::cout << "health bar pos :  " << enemies.GetEnemyHealthBar().getPosition().x << " , " << enemies.GetEnemyHealthBar().getPosition().y << std::endl;
			}
			//=================FINISH DRAW==================


			//=================WRITE THE DRAW BUFFER AS A FRAME===============
			window.display();

			if (player.GetHealth() <= 0)
			{
				gameState = GameState::GameOver;
			}
		}

		else if (gameState == GameState::GameOver)
		{
			// Render game over screen
			window.clear();

			window.draw(gui.GetGameOverText());

			window.display();

			// Check for restart or exit input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				gameState = GameState::Playing;
				player.Reset();
				bullets.clear();
				enemies.clear();
				clock.restart();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

	}
	return 0;
}

std::pair<int, int> GenerateRandomEnemySpawn()
{
	// Define the y range
	int y_min = 80;
	int y_max = 980;

	// Worked out later I didn't want the x to be random---switched this out as a quick fix. 
	int random_x = 1300;

	// Generate a random y position within the range [y_min, y_max]
	int random_y = y_min + std::rand() % (y_max - y_min + 1);

	return std::make_pair(random_x, random_y);
}

void SpawnEnemy(sf::Texture& texture)
{
	Enemy enemyShip(texture);
	auto position = GenerateRandomEnemySpawn();
	enemyShip.GetEnemySprite().setPosition(position.first, position.second);
	enemyShip.GetEnemyHealthBar().setPosition(enemyShip.GetEnemySprite().getPosition().x - 45, enemyShip.GetEnemySprite().getPosition().y - 25);
	enemies.push_back(enemyShip);
	std::cout << "enemies in vector" << enemies.size() << std::endl;

}

void UpdateFrameRate(sf::Clock& clock, GUI& gui)
{
	float deltaTime = clock.restart().asSeconds();
	float fps = 1.0f / deltaTime;
	gui.UpdateFrameRateText(fps);
}

