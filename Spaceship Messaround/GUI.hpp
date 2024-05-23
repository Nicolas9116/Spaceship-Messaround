#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GUI
{

private:

	sf::Text scoreText;
	sf::Font font;

public:

	GUI();


	sf::Text& GetScoreText();
	void UpdateScore(int score);

};

