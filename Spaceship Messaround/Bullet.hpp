#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Texture bulletTex;
	sf::Sprite bulletSprite;

	int bulletSpeed = 1;

public:

	Bullet();

	void SetupBulletSprite();

	int GetSpeed();

	sf::Sprite& GetBulletSprite();
};

