//
// Created by Mishal Zulfiqar on 28/01/2021.
//
#include <SFML/Graphics.hpp>
#include "Captives.h"
#ifndef DSAGAME_SUCCESSWINDOW_H
#define DSAGAME_SUCCESSWINDOW_H


class SuccessWindow {

private:

    //window sprite
    sf::RectangleShape succesWindowSprite;

    std::vector<Captives*> captivesSaved;

    //texts
    sf::Font successFont;
    sf::Text points;
    sf::Text health;
    sf::Text totalScore;
    sf::Text DragonsSaved;
    sf::Text SuccessMessage;
    sf::Text timeTaken;

public:
    //constructors
    SuccessWindow();
    SuccessWindow(float points, float hp, float hpMax, float timeTaken, std::vector<Captives*> captives);

    //init functions
    void initFont();
    void initTexts(float points , float hp, float hpMax, float timeTaken);
    void initSuccessWindowRectangle();

    //render
    void render(sf::RenderWindow* target);
    void renderCaptives(sf::RenderWindow *target);

};


#endif //DSAGAME_SUCCESSWINDOW_H
