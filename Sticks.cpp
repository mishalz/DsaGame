//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include "Sticks.h"

//<---------- CONSTRUCTORS AND DESTRUCTORS ---------->
Sticks::Sticks(float x, float y, float scaleX, float scaleY) {
    this->initSprite(x,y,scaleX,scaleY);
}

Sticks::~Sticks() {

}

//<------------ INITAILIZING FUNCTIONS ------------>

void Sticks::initSprite(float x, float y,float scaleX, float scaleY) {
    this->stickTexture.loadFromFile("Textures/stickSprite.png");
    this->stickSprite.setTexture(this->stickTexture);
    this->stickSprite.setScale(scaleX,scaleY);
    this->stickSprite.setPosition(x,y);

    this->Open=false;
}

//<------------ GETTERS AND SETTERS ------------>
sf::FloatRect Sticks::getBounds() {
    return this->stickSprite.getGlobalBounds();
}
void Sticks::setPosition(float x, float y) {
    this->stickSprite.setPosition(x,y);
}
bool Sticks::isOpen() {
    return this->Open;
}
void Sticks::setOpen(bool cond)
{
    this->Open=cond;
}
//<------------ RENDER FUNCTIONS ------------>
void Sticks::renderStick(sf::RenderWindow* target) {
    target->draw(this->stickSprite);
}





