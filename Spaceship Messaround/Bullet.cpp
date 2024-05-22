#include "Bullet.hpp"

#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>

static bool textureLoaded = false;


Bullet::Bullet() 
{
	if (!textureLoaded)
	{
		std::cout << "Loading texture from: " << "C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/blue_lazer.png" << std::endl;
		std::cout << "File exists: " << std::filesystem::exists("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/blue_lazer.png") << std::endl;
		if (!bulletTex.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/blue_lazer.png"))
		{
			std::cout << "FAILED TO LOAD BULLET TEXTURE" << std::endl;
		}
		else
		{
			textureLoaded = true;
		}
	}

	void SetupBulletSprite();
}

void Bullet::SetupBulletSprite()
{
    bulletSprite.setTexture(bulletTex);
    bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);//set origin to centre
    bulletSprite.setScale(0.1f, 0.1f); // Ensure the texture is scaled down without distortion
    bulletSprite.setRotation(180);
}

int Bullet::GetSpeed()
{
    return bulletSpeed;
}

sf::Sprite& Bullet::GetBulletSprite()
{
    return bulletSprite;
}
