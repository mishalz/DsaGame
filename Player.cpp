//
// Created by Mishal Zulfiqar on 20/01/2021.
//

#include "Player.h"

//<----------------- CONSTRUCTORS AND DESTRUCTORS ----------------->
/* constructing the Player object and also deleting it */
Player::Player() {

    //calling all the init functions
    this->initVariables();
    this->initPlayerTexture();
    this->initPlayerSprite();
}

Player::~Player() {

}

//<---------------------- INIT FUNCTIONS ---------------------->
/* separate functions for initializing each element */

void Player::initVariables() {
    this->movementSpeed=10.f;
    this->hpMax=100;
    this->hp= this->hpMax;
    this->attackCoolDownMax=10.f;
    this->attackCoolDown= this->attackCoolDownMax;
    this->enemyCollisionCoolDownMax=10.f;
    this->enemyCollisionCoolDown= this->enemyCollisionCoolDownMax;
}

void Player::initPlayerTexture() {

    //load the texture
    if(!this->PlayerTexture.loadFromFile("Textures/PlayerSpriteFront1.png"))
    {
        std::cout << "ERROR :: initPlayerTexture :: Player.cpp :: Player Texture could not be loaded." << std::endl;
    }
}

void Player::initPlayerSprite() {

    //set the texture to the sprite
    this->PlayerSprite.setTexture(this->PlayerTexture);

    //set the position of the player
    this->PlayerSprite.setPosition(0.f,60.f); //on the upper left corner

    //set scale
    this->PlayerSprite.setScale(0.7f,0.7f);

}

//<---------------------- UPDATE FUNCTIONS ---------------------->
/* updating values on the basis of events from the last frame */

void Player::PlayerUpdate() {
    this->updateAttack();
    this->updateCollisionCooldown();
}
void Player::updateAttack() {
    if(this->attackCoolDown < this->attackCoolDownMax)
    {
        this->attackCoolDown += 0.5f;
    }
}
void Player::updateCollisionCooldown() {
    if(this->enemyCollisionCoolDown < this->enemyCollisionCoolDownMax)
    {
        this->enemyCollisionCoolDown += 0.5f;
    }
}
//<---------------------- RENDER FUNCTIONS ---------------------->
/* Render the newly updated values onto the window to display for the current frame */

void Player::PlayerRender(sf::RenderTarget& target) {

    //drawing the sprite to the screen
    target.draw(this->PlayerSprite);

}

//<---------------------- GETTERS AND SETTERS ---------------------->

/* setting the sprite */
void Player::setSpriteTexture(std::string texturePath) {
    this->PlayerTexture.loadFromFile(texturePath);
    this->PlayerSprite.setTexture(this->PlayerTexture);
}
sf::Vector2f Player::getPos() {
    return this->PlayerSprite.getPosition();
}
sf::FloatRect Player::getGlobalBounds() {
    return this->PlayerSprite.getGlobalBounds();
}
void Player::setPosition(float x, float y) {
    this->PlayerSprite.setPosition(x,y);
}
sf::Vector2f Player::getVelocity() {
    return this->velocity;
}
void Player::setVelocity(sf::Vector2f vec) {
    this->velocity=vec;
}
float Player::getMovementSpeed() {
    return this->movementSpeed;
}
const int &Player::getHpMax() const {
    return this->hpMax;
}

const int &Player::getHp() const {
    return this->hp;
}

void Player::setHp(int hp) {
    this->hp=hp;
}

void Player::looseHp(int value) {
    this->hp -= value;
    if(this->hp < 0)
    {
        this->hp=0;
    }
}

//<---------------------- OTHER FUNCTIONS ---------------------->
/* According to the movement speed, the sprite's position is changed*/
void Player::move() {
    this->PlayerSprite.move(this->movementSpeed*this->velocity.x,this->movementSpeed*this->velocity.y);
}

const bool Player::canAttack() {
    if(this->attackCoolDown >= this->attackCoolDownMax)
    {
        this->attackCoolDown=0.f;
        return true;
    }
    return false;
}

const bool Player::canCollide() {
    if(this->enemyCollisionCoolDown >= this->enemyCollisionCoolDownMax)
    {
        this->enemyCollisionCoolDown=0.f;
        return true;
    }
    return false;
}










