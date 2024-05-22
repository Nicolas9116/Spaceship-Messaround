#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:

	sf::Sprite playerSprite;
	sf::Texture *playerTex;

	int currentHealth = 0;
	int maxhealth = 5;
	

public:


	Player(sf::Texture *texture)//Constructor -> in the header this time ->about to build Bullet class, will try putting it in the source
	{	
		playerTex = texture;
		playerSprite.setTexture(*texture);
		playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
		playerSprite.setScale(.1, .1);
		playerSprite.setRotation(90);
		playerSprite.setPosition(640.f, 540.f);
		currentHealth = maxhealth;//set health to max
	}

	sf::Sprite& GetSprite();

};

