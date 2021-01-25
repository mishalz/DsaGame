//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include "Enemy.h"
//<------------- CONSTRUCTORS AND DESTRUCTORS ------------->
Enemy::Enemy(){}

Enemy::Enemy(sf::Vector2f startingP, sf::Vector2f EndingP, float mspeed)
{
    this->initVariables();
    this->setMovementSpeed(mspeed);
    this->initTexture();
    this->initSprite();
    this->initPositions(startingP,EndingP);
    this->initHealthBar();
}

Enemy::~Enemy() {

}

//<------------- INITIALIZING FUNCTIONS ------------->

void Enemy::initVariables()
{
    this->hpMax=10;
    this->hp= this->hpMax;
}
void Enemy::initSprite() {
    this->enemySprite.setTexture(this->texture);
    this->enemySprite.setScale(0.05f,0.05f);
}

void Enemy::initTexture() {
    this->texture.loadFromFile("Textures/enemy.png");
    this->texture.setSmooth(true);
}
void Enemy::initPositions(sf::Vector2f startingP, sf::Vector2f EndingP)
{

    this->enemySprite.setPosition(startingP);
    this->startingPos=startingP;
    this->EndingPos=EndingP;
}
void Enemy::initHealthBar() {
    //init Enemy health
    this->enemyHpBar.setSize(sf::Vector2f(30.f,8.f));
    this->enemyHpBar.setFillColor(sf::Color::Green);
    this->enemyHpBarBack=this->enemyHpBar;
    this->enemyHpBarBack.setFillColor(sf::Color(25,25,25,200));
}
//<------------- SETTERS AND GETTERS ------------->
void Enemy::setMovementSpeed(float speed)
{
    this->movementSpeed=speed;
}
sf::FloatRect Enemy::getBounds()
{
    return this->enemySprite.getGlobalBounds();
}
const int &Enemy::getHpMax() const {
    return this->hpMax;
}

const int &Enemy::getHp() const {
    return this->hp;
}

void Enemy::setHp(int hp) {
    this->hp=hp;
}

void Enemy::looseHp(int value) {
    this->hp -= value;
    if(this->hp < 0)
    {
        this->hp=0;
    }
}
//<------------- UPDATE FUNCTIONS ------------->
void Enemy::update() {
    this->updateHealthBar();
}
void Enemy::updateHealthBar() {
    float hpPercent = static_cast<float>(this->getHp())/ this->getHpMax();
    this->enemyHpBarBack.setPosition(this->getBounds().left -5.f,this->getBounds().top );
    this->enemyHpBar.setPosition(this->getBounds().left -5.f,this->getBounds().top);
    this->enemyHpBar.setSize(sf::Vector2f(30 * hpPercent, this->enemyHpBarBack.getSize().y));

    if(hpPercent < 0.25)
    {
        this->enemyHpBar.setFillColor(sf::Color::Red);
    }
}
//<------------- RENDER FUNCTIONS ------------->
void Enemy::render(sf::RenderWindow *target) {

    target->draw(this->enemySprite);
    this->renderEnemyHealthBar(target);

}
void Enemy::renderEnemyHealthBar(sf::RenderWindow *target){
    target->draw(this->enemyHpBarBack);
    target->draw(this->enemyHpBar);
}

void Enemy::move(float x, float y) {

    this->enemySprite.move(this->movementSpeed * x,this->movementSpeed * y);

    if(this->enemySprite.getGlobalBounds().left == this->EndingPos.x)
    {
        this->movementSpeed=-1.f;
        this->enemySprite.setScale(-0.05f,0.05f);
    }
    else if(this->enemySprite.getGlobalBounds().left +this->enemySprite.getGlobalBounds().width == this->startingPos.x)
    {
        this->movementSpeed=1.f;
        this->enemySprite.setScale(0.05f,0.05f);
    }

}




