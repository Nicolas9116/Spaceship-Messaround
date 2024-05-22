#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
	sf::Sprite enemySprite;
	int health = 3;
	int enemySpeed = 10;

public:

	Enemy(sf::Texture& texture);

	int& GetEnemyHealth();

	sf::Sprite& GetEnemySprite();
};

