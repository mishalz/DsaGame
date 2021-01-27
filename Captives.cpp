//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include "Captives.h"

//<----------- CONSTRUCTORS AND DESTRUCTORS ----------->
Captives::Captives(sf::Vector2f pos,int Id) {

    this->initVariables(Id);
    this->initCaptiveSprite(pos);

}
Captives::Captives() {}
Captives::~Captives() {

}

//<-------------- INITIALIZING FUNCTIONS -------------->
void Captives::initCaptiveSprite(sf::Vector2f pos) {
    this->captiveTexture.loadFromFile("Textures/prisonersSprite.png");
    this->captiveSprite.setTexture(this->captiveTexture);
    this->captiveSprite.setScale(0.09f,0.09f);
    this->captiveSprite.setPosition(pos);
}
void Captives::initVariables(int Id)
{
    this->captiveId=Id;
}
//<--------------- SETTERS AND GETTERS ---------------->
void Captives::setPosition(sf::Vector2f pos) {
    this->captiveSprite.setPosition(pos);
}
sf::FloatRect Captives::getBounds() {
    return this->captiveSprite.getGlobalBounds();
}
void Captives::setScale(float x, float y){
    this->captiveSprite.setScale(x,y);
}
int Captives::getId()
{
    return this->captiveId;
}
//<----------------- UPDATE FUNCTIONS ----------------->

//<----------------- RENDER FUNCTIONS ----------------->
void Captives::renderCaptive(sf::RenderWindow *target) {
    target->draw(this->captiveSprite);
}


