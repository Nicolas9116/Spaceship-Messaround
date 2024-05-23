#include "GUI.hpp"
#include <iostream>

GUI::GUI()
{
    //Score setup
    if (!scoreTextFont.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Fonts/score_board_font.ttf")) 
    {
        std::cout << "Couldn't load font" << std::endl;
    }
    scoreText.setFont(scoreTextFont);
    scoreText.setCharacterSize(38);
	scoreText.setPosition(10, 10);
	scoreText.setString("SCORE : ");

    //healthBar setup -> Two pieces are the red health indication, and the second piece is the surrounding boarder
    healthBar.setSize(sf::Vector2f(200, 30));
    healthBar.setOrigin(healthBar.getGlobalBounds().width / 2, healthBar.getGlobalBounds().height / 2);
    healthBar.setFillColor(sf::Color::Red);
    healthBar.setPosition(150, 1000);

    healthBarBacking.setSize(sf::Vector2f(210, 40));
    healthBarBacking.setOrigin(healthBarBacking.getGlobalBounds().width / 2, healthBarBacking.getGlobalBounds().height / 2);
    healthBarBacking.setFillColor(sf::Color::Transparent);
    healthBarBacking.setOutlineColor(sf::Color::White);
    healthBarBacking.setOutlineThickness(1.5);
    healthBarBacking.setPosition(150, 1000);
    
    gameOverText.setFont(scoreTextFont);
    gameOverText.setString("Game Over\nPress R to Restart\nPress Esc to Exit");
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(300, 400);
};

sf::Text& GUI::GetGameOverText()
{
    return gameOverText;
}

sf::Text& GUI::GetScoreText()
{
	return scoreText;
}

void GUI::UpdateScore(int score)
{
    scoreText.setString("SCORE : " + std::to_string(score));
}

sf::RectangleShape& GUI::GetHealthBar()
{
    return healthBar;
}

sf::RectangleShape& GUI::GetHealthBarBacking()
{
    return healthBarBacking;
}

void GUI::UpdateHealthBar(int remaininghealth)
{
    healthBar.setSize(sf::Vector2f(remaininghealth * 40, 30));
}
