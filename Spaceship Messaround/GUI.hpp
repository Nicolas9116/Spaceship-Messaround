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

	sf::RectangleShape dashBar;
	sf::RectangleShape dashBarBacking;

	sf::RectangleShape bombBar;
	sf::RectangleShape bombBarBacking;

	sf::Text gameOverText;

	sf::Text frameRateText;

	sf::RectangleShape explosion;

public:

	GUI();
	sf::Text& GetFrameRateText();
	sf::Text& GetGameOverText();
	sf::Text& GetScoreText();

	void UpdateScore(int& score);

	sf::RectangleShape& GetHealthBar();
	sf::RectangleShape& GetHealthBarBacking();
	sf::RectangleShape& GetDashBar();
	sf::RectangleShape& GetDashBarBacking();
	sf::RectangleShape& GetBombBar();
	sf::RectangleShape& GetBombBarBacking();
	sf::RectangleShape& GetExplosion();

	void UpdateHealthBar(int& remaininghealth);
	void UpdateFrameRateText(float& framerate);
	void UpdateDashBar(int& dashbarenergy);
	void UpdateBombBar(int& scorecharge);
};

