#include "Player.hpp"
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
