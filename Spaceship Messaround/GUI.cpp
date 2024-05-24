#include "GUI.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

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
    healthBar.setPosition(150, 1020);

    healthBarBacking.setSize(sf::Vector2f(210, 40));
    healthBarBacking.setOrigin(healthBarBacking.getGlobalBounds().width / 2, healthBarBacking.getGlobalBounds().height / 2);
    healthBarBacking.setFillColor(sf::Color::Transparent);
    healthBarBacking.setOutlineColor(sf::Color::White);
    healthBarBacking.setOutlineThickness(1.5);
    healthBarBacking.setPosition(150, 1020);

    dashBar.setSize(sf::Vector2f(180, 30));
    dashBar.setOrigin(dashBar.getGlobalBounds().width / 2, dashBar.getGlobalBounds().height / 2);
    dashBar.setFillColor(sf::Color::Blue);
    dashBar.setPosition(360, 1020);

    dashBarBacking.setSize(sf::Vector2f(190, 40));
    dashBarBacking.setOrigin(dashBarBacking.getGlobalBounds().width / 2, dashBarBacking.getGlobalBounds().height / 2);
    dashBarBacking.setFillColor(sf::Color::Transparent);
    dashBarBacking.setOutlineColor(sf::Color::White);
    dashBarBacking.setOutlineThickness(1.5);
    dashBarBacking.setPosition(360, 1020);

    bombBar.setSize(sf::Vector2f(100, 10));
    bombBar.setOrigin(bombBar.getGlobalBounds().width / 2, bombBar.getGlobalBounds().height / 2);
    bombBar.setFillColor(sf::Color::Yellow);
    bombBar.setPosition(100, 985);

    bombBarBacking.setSize(sf::Vector2f(110, 15));
    bombBarBacking.setOrigin(bombBarBacking.getGlobalBounds().width / 2, bombBarBacking.getGlobalBounds().height / 2);
    bombBarBacking.setFillColor(sf::Color::Transparent);
    bombBarBacking.setOutlineColor(sf::Color::White);
    bombBarBacking.setOutlineThickness(1.5);
    bombBarBacking.setPosition(100, 985);
    
    gameOverText.setFont(scoreTextFont);
    gameOverText.setString("Game Over\nPress R to Restart\nPress Esc to Exit");
    gameOverText.setCharacterSize(50);
    gameOverText.setPosition(300, 400);

    frameRateText.setFont(scoreTextFont);
    frameRateText.setCharacterSize(32);
    frameRateText.setPosition(1050, 10);
    frameRateText.setString("FPS ");

    explosion.setSize(sf::Vector2f(1280, 1080));
    explosion.setOrigin(explosion.getGlobalBounds().width / 2, explosion.getGlobalBounds().height / 2);
    explosion.setFillColor(sf::Color::Yellow);
    explosion.setPosition(640, 540);
}
sf::Text& GUI::GetFrameRateText()
{
    return frameRateText;
}

sf::Text& GUI::GetGameOverText()
{
    return gameOverText;
}

sf::Text& GUI::GetScoreText()
{
	return scoreText;
}

void GUI::UpdateFrameRateText(float& framerate)
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << framerate;
    frameRateText.setString("FPS " + stream.str());
}

void GUI::UpdateDashBar(int& dashbarenergy)
{
    dashBar.setSize(sf::Vector2f(dashbarenergy, 30));
}

void GUI::UpdateBombBar(int& scorecharge)
{
    bombBar.setSize(sf::Vector2f(scorecharge, 15));
}

void GUI::UpdateScore(int& score)
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

sf::RectangleShape& GUI::GetDashBar()
{
    return dashBar;
}

sf::RectangleShape& GUI::GetDashBarBacking()
{
    return dashBarBacking;
}

sf::RectangleShape& GUI::GetBombBar()
{
    return bombBar;
}

sf::RectangleShape& GUI::GetBombBarBacking()
{
    return bombBarBacking;
}

sf::RectangleShape& GUI::GetExplosion()
{
    return explosion;
}

void GUI::UpdateHealthBar(int& remaininghealth)
{
    healthBar.setSize(sf::Vector2f(remaininghealth * 40, 30));
}
