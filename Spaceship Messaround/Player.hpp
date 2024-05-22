#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:

	sf::Sprite playerSprite;
	sf::Texture playerTex;

	int currentHealth = 0;
	int maxhealth = 5;
	

public:


	Player()//Constructor -> in the header this time ->about to build Bullet class, will try putting it in the source
	{		
		SetUpPlayerSprite();//set scale,locat,rotat,tex,origin
		currentHealth = maxhealth;//set health to max
	}

	void SetUpPlayerSprite();

	sf::Sprite& GetSprite();

};

