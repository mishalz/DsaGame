//
// Created by Mishal Zulfiqar on 28/01/2021.
//
#include <SFML/Graphics.hpp>

#ifndef DSAGAME_GAMEOVERWINDOW_H
#define DSAGAME_GAMEOVERWINDOW_H


class GameOverWindow {

private:

    //window sprite
    sf::RectangleShape gameOverWindowSprite;

    //texts
    sf::Font gameOverFont;
    sf::Text GameOverMessage;

public:
    //constructors
    GameOverWindow();

    //init functions
    void initFont();
    void initTexts();
    void initGameOverWindowRectangle();

    //render
    void render(sf::RenderWindow* target);

};


#endif //DSAGAME_GAMEOVERWINDOW_H
