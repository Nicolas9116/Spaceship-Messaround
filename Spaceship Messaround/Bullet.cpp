#include "Bullet.hpp"

#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>

static bool textureLoaded = false;


Bullet::Bullet(sf::Texture *texture) 
{
	bulletSprite.setTexture(*texture);
	bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);//set origin to centre
	bulletSprite.setScale(0.1f, 0.1f); // Ensure the texture is scaled down without distortion
	bulletSprite.setRotation(180);
}

sf::Texture& Bullet::GetBulletTexture()
{
	return bulletTex;
}

int& Bullet::GetSpeed()
{
    return bulletSpeed;
}

sf::Sprite& Bullet::GetBulletSprite()
{
    return bulletSprite;
}
