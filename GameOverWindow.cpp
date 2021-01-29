//
// Created by Mishal Zulfiqar on 28/01/2021.
//

#include "GameOverWindow.h"
GameOverWindow::GameOverWindow() {
    this->initFont();
    this->initTexts();
    this->initGameOverWindowRectangle();
}

//init functions
void GameOverWindow::initFont() {
    this->gameOverFont.loadFromFile("Fonts/AtlantisInternational.ttf");
}

void GameOverWindow::initTexts() {

    this->GameOverMessage.setFont(this->gameOverFont);
    this->GameOverMessage.setCharacterSize(60);
    this->GameOverMessage.setFillColor(sf::Color::White);
    this->GameOverMessage.setString(" G A M E   O V E R.");
    this->GameOverMessage.setPosition(200.f, 310.f);

}

void GameOverWindow::initGameOverWindowRectangle() {
    this->gameOverWindowSprite.setSize(sf::Vector2f(460.f,200.f));
    this->gameOverWindowSprite.setFillColor(sf::Color::Black);
    this->gameOverWindowSprite.setOutlineThickness(5);
    this->gameOverWindowSprite.setOutlineColor(sf::Color::Red);
    this->gameOverWindowSprite.setPosition(180.f,260.f);
}

//render functions
void GameOverWindow::render(sf::RenderWindow *target) {
    target->draw(this->gameOverWindowSprite);
    target->draw(this->GameOverMessage);

}