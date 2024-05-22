#include "Bullet.hpp"

Bullet::Bullet()
{
    if (!bulletTex.loadFromFile("C:/Users/vampi/source/repos/RPG_Game/RPG_Game/Sprites/blue_lazer.png"))
    {
        std::cout << "FAILED TO LOAD BULLET TEXTURE" << std::endl;
    }
    else
    {
        SetupBulletSprite();
    }
}

void Bullet::SetupBulletSprite()
{
    bulletSprite.setTexture(bulletTex);
    bulletSprite.setScale(0.1f, 0.1f); // Ensure the texture is scaled down without distortion
    bulletSprite.setRotation(180);
    bulletSprite.setOrigin(bulletSprite.getGlobalBounds().width / 2, bulletSprite.getGlobalBounds().height / 2);
}

int Bullet::GetSpeed()
{
    return bulletSpeed;
}

sf::Sprite& Bullet::GetBulletSprite()
{
    return bulletSprite;
}
