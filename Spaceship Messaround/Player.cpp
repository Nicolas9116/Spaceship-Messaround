#include "Player.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <algorithm>

Player::Player(sf::Texture &texture)
{
	playerSprite.setTexture(texture);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(.1, .1);
	playerSprite.setRotation(90);
	playerSprite.setPosition(640, 540);
	currentHealth = maxhealth;//set health to max
}

int& Player::GetScore()
{
	return score;
}

void Player::UpdateScore(int score)
{
	this->score += score;
}

int& Player::GetHealth()
{
	return currentHealth;
}

void Player::TakeDamage(int damage)
{
	currentHealth -= damage;
}

int& Player::GetBombCharge()
{
	return bombCharge;
}

void Player::UpdateBombCharge(int charge)
{
	this->bombCharge += charge;
}

void Player::ResetBombCharge()
{
	this->bombCharge = 0;
}

void Player::ThrowBomb(std::vector<Enemy>& enemies)
{
	for (auto enemy = enemies.begin(); enemy != enemies.end();)
	{
		enemy = enemies.erase(enemy);
	}
	this->ResetBombCharge();
}


sf::Sprite& Player::GetSprite()
{
	return playerSprite;
}

sf::Vector2f& Player::GetAcceleration()
{
	return acceleration;
}

float& Player::GetAccelerationForce()
{
	return accelerationForce;
}

sf::Vector2f& Player::GetVelocity()
{
	return velocity;
}

void Player::UpdateAcceleration(sf::Vector2f newAcceleration)
{
	acceleration += newAcceleration;
}

void Player::ResetAcceleration()
{
	acceleration = sf::Vector2f(0, 0);
}

void Player::ResetVerticalVelocity()
{
	velocity.y = velocity.y * 0.5f;
}

void Player::ResetHorizontalVelocity()
{
	velocity.x = velocity.x * 0.5f;
}

void Player::UpdateVelocity(sf::Vector2f acceleration)
{
	velocity += acceleration;

	velocity.x = std::clamp(velocity.x, -maxVelocity, maxVelocity);
	velocity.y = std::clamp(velocity.y, -maxVelocity, maxVelocity);
}

void Player::ApplyAirResistance()
{
	velocity *= 0.98f;
}

void Player::Reset()
{
	score = 0;
	playerSprite.setPosition(640, 540);
	currentHealth = maxhealth;//set health to max
}
