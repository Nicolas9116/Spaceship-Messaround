#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GUI
{

private:

	sf::Text scoreText;
	sf::Font scoreTextFont;

	sf::RectangleShape healthBar;
	sf::RectangleShape healthBarBacking;

	sf::Text gameOverText;

	sf::Text frameRateText;

public:

	GUI();
	sf::Text& GetFrameRateText();
	sf::Text& GetGameOverText();
	sf::Text& GetScoreText();
	void UpdateScore(int score);
	sf::RectangleShape& GetHealthBar();
	sf::RectangleShape& GetHealthBarBacking();
	void UpdateHealthBar(int remaininghealth);
	void UpdateFrameRateText(float framerate);

};

