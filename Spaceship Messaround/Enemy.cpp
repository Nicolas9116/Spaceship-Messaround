#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& texture)
{
    enemySprite.setTexture(texture);
    enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
    enemySprite.setScale(0.3, 0.3);
    enemySprite.setRotation(270);

};


int& Enemy::GetEnemyHealth()
{
    return health;
}

sf::Sprite& Enemy::GetEnemySprite()
{
    return enemySprite;
}