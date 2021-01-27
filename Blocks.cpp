//
// Created by Mishal Zulfiqar on 22/01/2021.
//

#include "Blocks.h"
#include <iostream>

//<----------------- CONSTRUCTORS AND DESTRUCTORS ----------------->
/* constructing the Block object and also deleting it */

Blocks::Blocks() {

}

Blocks::Blocks(float posX, float posY, float angle) {

    //calling all the init functions
    this->initTexture();
    this->initSprite(posX,posY,angle);

}

Blocks::~Blocks() {

}

//<---------------------- INIT FUNCTIONS ---------------------->
/* separate functions for initializing each element */

void Blocks::initSprite(float posX, float posY, float angle) {
    this->BlockSprite.setTexture(this->BlockTexture);
    this->BlockSprite.setPosition(posX,posY);
    this->BlockSprite.setScale(0.15f,0.15f);
    this->BlockSprite.rotate(angle);
}

void Blocks::initTexture() {
    if(!this->BlockTexture.loadFromFile("Textures/SpriteRedBrick.jpg"))
    {
        std::cout << "ERROR :: initBlockTexture :: Blocks.cpp :: Block Texture could not be loaded." << std::endl;
    }
}

//<---------------------- UPDATE FUNCTIONS ---------------------->
/* updating values on the basis of events from the last frame */

//<---------------------- RENDER FUNCTIONS ---------------------->
/* Render the newly updated values onto the window to display for the current frame */

void Blocks::blockRender(sf::RenderTarget* target) {
    target->draw(this->BlockSprite);
}

sf::FloatRect Blocks::getGlobalBounds() {
    return this->BlockSprite.getGlobalBounds();
}

//<---------------------- OTHER FUNCTIONS ---------------------->
