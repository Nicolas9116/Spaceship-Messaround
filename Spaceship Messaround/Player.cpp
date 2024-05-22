#include "Player.hpp"



void Player::SetUpPlayerSprite()
{
	if (!playerTex.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Sprites/player_ship.png"))
	{
		std::cout << "FAILED TO LOAD PLAYER_SPRITE" << std::endl;

	}
	playerSprite.setTexture(playerTex);
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);
	playerSprite.setScale(.1, .1);
	playerSprite.setRotation(90);
	playerSprite.setPosition(640.f, 540.f);
}

sf::Sprite& Player::GetSprite()
{
	return playerSprite;
}
