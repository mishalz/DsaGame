//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include "Captives.h"

//<----------- CONSTRUCTORS AND DESTRUCTORS ----------->
Captives::Captives() {

    this->initCaptiveSprite();
}

Captives::~Captives() {

}

//<-------------- INITIALIZING FUNCTIONS -------------->
void Captives::initCaptiveSprite() {
    this->captiveTexture.loadFromFile("Textures/prisonersSprite.png");
    this->captiveSprite.setTexture(this->captiveTexture);
    this->captiveSprite.setScale(0.1f,0.1f);
}

//<--------------- SETTERS AND GETTERS ---------------->
void Captives::setPosition(sf::Vector2f pos) {
    this->captiveSprite.setPosition(pos);
}

//<----------------- UPDATE FUNCTIONS ----------------->

//<----------------- RENDER FUNCTIONS ----------------->
void Captives::renderCaptive(sf::RenderWindow *target) {
    target->draw(this->captiveSprite);
}

