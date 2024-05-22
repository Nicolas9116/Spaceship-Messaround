#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Texture bulletTex;
	sf::Sprite bulletSprite;

	int bulletSpeed = 10;

public:

	Bullet(sf::Texture *texture);

	void SetupBulletSprite();

	int& GetSpeed();

	sf::Sprite& GetBulletSprite();
	sf::Texture& GetBulletTexture();
};

