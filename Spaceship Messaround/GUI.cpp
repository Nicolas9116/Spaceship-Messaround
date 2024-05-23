#include "GUI.hpp"
#include <iostream>

GUI::GUI()
{
    if (!font.loadFromFile("C:/Users/vampi/source/repos/Spaceship Messaround/Spaceship Messaround/Fonts/score_board_font.ttf")) 
    {
        std::cout << "Couldn't load font" << std::endl;
    }
    scoreText.setFont(font);
	scoreText.setPosition(10, 10);
	scoreText.setString("SCORE : ");
};

sf::Text& GUI::GetScoreText()
{
	return scoreText;
}

void GUI::UpdateScore(int score)
{
    scoreText.setString("SCORE : " + std::to_string(score));
}
