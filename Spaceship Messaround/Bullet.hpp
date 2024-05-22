#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Sprite bulletSprite;

	int bulletSpeed = 10;

public:

	Bullet(sf::Texture &texture);

	int& GetSpeed();

	sf::Sprite& GetBulletSprite();
};

