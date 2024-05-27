#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{

	sf::RectangleShape enemyHealthBar;

	sf::Sprite enemySprite;
	int health = 3;
	int enemySpeed = 8;

public:

	Enemy(sf::Texture& texture);

	int& GetEnemyHealth();

	sf::Sprite& GetEnemySprite();
	int& GetSpeed();
	sf::RectangleShape& GetEnemyHealthBar();
	void TakeDamage(int damage);
	void UpdateEnemyHealthBar();
};

