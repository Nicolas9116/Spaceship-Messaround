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

	float maxVelocity = 10;
	float accelerationForce = 0.5f;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	

public:


	Player(sf::Texture &texture);

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
};

