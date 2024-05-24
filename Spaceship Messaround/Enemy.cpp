#include "Enemy.hpp"

Enemy::Enemy(sf::Texture& texture)
{
    enemySprite.setTexture(texture);
    enemySprite.setOrigin(enemySprite.getGlobalBounds().width / 2, enemySprite.getGlobalBounds().height / 2);
    enemySprite.setScale(0.3, 0.3);
    enemySprite.setRotation(270);

    enemyHealthBar.setOrigin(enemyHealthBar.getGlobalBounds().width / 2, enemyHealthBar.getGlobalBounds().height / 2);
    enemyHealthBar.setSize(sf::Vector2f(30, 5));
    enemyHealthBar.setFillColor(sf::Color::Red);
    enemyHealthBar.setOutlineColor(sf::Color::White);
    enemyHealthBar.setOutlineThickness(.75f);
};


int& Enemy::GetEnemyHealth()
{
    return health;
}

int& Enemy::GetSpeed()
{
    return enemySpeed;
}

sf::Sprite& Enemy::GetEnemySprite()
{
    return enemySprite;
}

sf::RectangleShape& Enemy::GetEnemyHealthBar()
{
    return enemyHealthBar;
}

void Enemy::TakeDamage(int damage)
{
    health -= damage;
}

void Enemy::UpdateEnemyHealthBar()
{
    enemyHealthBar.setSize(sf::Vector2f(health * 10, 5));
}

