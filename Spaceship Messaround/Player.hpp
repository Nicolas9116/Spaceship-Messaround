#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Player
{
private:

	sf::Sprite playerSprite;

	int currentHealth = 0;
	int maxhealth = 5;

	float maxVelocity = 12.5;
	float accelerationForce = 1;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;

	int score = 0;
	int bombCharge = 100;

public:
	Player(sf::Texture& texture);

	int& GetScore();
	void UpdateScore(int score);

	int& GetHealth();
	void TakeDamage(int damage);

	int& GetBombCharge();
	void UpdateBombCharge(int charge);
	void ResetBombCharge();
	//void ThrowBomb(std::vector<Enemy>& enemies);

	sf::Sprite& GetSprite();

	sf::Vector2f& GetAcceleration();
	float& GetAccelerationForce();

	sf::Vector2f& GetVelocity();

	void UpdateAcceleration(sf::Vector2f newAcceleration);
	void ResetAcceleration();
	void ResetVerticalVelocity();
	void ResetHorizontalVelocity();

	void UpdateVelocity(sf::Vector2f acceleration);

	void ApplyAirResistance();

	void Reset();
};


