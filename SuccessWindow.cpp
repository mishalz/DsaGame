//
// Created by Mishal Zulfiqar on 28/01/2021.
//

#include "SuccessWindow.h"
#include "string"
#include <iostream>

SuccessWindow::SuccessWindow() {
    this->initFont();
    this->initSuccessWindowRectangle();
}

SuccessWindow::SuccessWindow(float points, float hp, float hpMax, float timeTaken, std::vector<Captives*> captives) {
    this->initFont();
    this->initTexts(points,hp,hpMax,timeTaken);
    this->initSuccessWindowRectangle();
    this->captivesSaved=captives;
}

//init functions
void SuccessWindow::initFont() {
    this->successFont.loadFromFile("Fonts/AtlantisInternational.ttf");
}

void SuccessWindow::initTexts(float points, float hp, float hpMax, float timeTaken) {


    this->SuccessMessage.setFont(this->successFont);
    this->SuccessMessage.setCharacterSize(60);
    this->SuccessMessage.setFillColor(sf::Color::White);
    std::string sm=" YOU MADE IT.";
    this->SuccessMessage.setString(sm);
    this->SuccessMessage.setPosition(220.f, 170.f);

    this->points.setFont(this->successFont);
    this->points.setCharacterSize(40);
    this->points.setFillColor(sf::Color::White);
    sm="Points:  "+ std::to_string(points);
    this->points.setString(sm);
    this->points.setPosition(250.f, 260.f);

    this->health.setFont(this->successFont);
    this->health.setCharacterSize(40);
    this->health.setFillColor(sf::Color::White);
    sm="Health :  "+ std::to_string(hp) + " / " + std::to_string(hpMax);
    this->health.setString(sm);
    this->health.setPosition(250.f, 330.f);

    this->timeTaken.setFont(this->successFont);
    this->timeTaken.setCharacterSize(40);
    this->timeTaken.setFillColor(sf::Color::White);
    sm="Time Taken:  "+ std::to_string(timeTaken);
    this->timeTaken.setString(sm);
    this->timeTaken.setPosition(250.f, 390.f);

    this->DragonsSaved.setFont(this->successFont);
    this->DragonsSaved.setCharacterSize(40);
    this->DragonsSaved.setFillColor(sf::Color::White);
    this->DragonsSaved.setString("Dragons saved: ");
    this->DragonsSaved.setPosition(250.f, 450.f);

    this->totalScore.setFont(this->successFont);
    this->totalScore.setCharacterSize(40);
    this->totalScore.setFillColor(sf::Color::White);
    this->totalScore.setString("Total Score: ");
    this->totalScore.setPosition(250.f, 510.f);

}

void SuccessWindow::initSuccessWindowRectangle() {
    this->succesWindowSprite.setSize(sf::Vector2f(550.f,500.f));
    this->succesWindowSprite.setFillColor(sf::Color::Black);
    this->succesWindowSprite.setOutlineThickness(5);
    this->succesWindowSprite.setOutlineColor(sf::Color(115,201,235, 255));
    this->succesWindowSprite.setPosition(200.f,160.f);
}

//render functions
void SuccessWindow::render(sf::RenderWindow *target) {
    target->draw(this->succesWindowSprite);
    target->draw(this->SuccessMessage);
    target->draw(this->points);
    target->draw(this->health);
    target->draw(this->timeTaken);
    target->draw(this->DragonsSaved);
    target->draw(this->totalScore);
    this->renderCaptives(target);
}
void SuccessWindow::renderCaptives(sf::RenderWindow *target)
{
    int counter=0;
    for(auto &cap : this->captivesSaved)
    {
        cap->setPosition(sf::Vector2f (480+(30*counter), 465));
        cap->renderCaptive(target);
        counter++;
    }
}

