//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include "Bullets.h"


//<---------- CONSTRUCTORS AND DESTRUCTORS ----------->
Bullets::Bullets() {

}
Bullets::Bullets(float pos_x, float pos_y,float width, float height, float mSpeed, std::string direction) {

    this->BulletTexture.loadFromFile("Textures/bullet.png");
    this->BulletShape.setTexture(this->BulletTexture);
    this->BulletShape.scale(0.015f,0.015f);

    this->BulletDirection=direction;
    this->setPos(pos_x,pos_y,width,height);
    this->setDirection();
    this->movementSpeed=mSpeed;
}

Bullets::~Bullets() {

}

//<----------- SETTERS AND GETTERS ----------->

const sf::FloatRect Bullets::getBounds() const {
    return this->BulletShape.getGlobalBounds();
}
float Bullets::getWidth() {
    Bullets* b=new Bullets();
    return (b->BulletShape.getGlobalBounds().width)/2;
}
void Bullets::setPos(float x, float y,float width, float height) {
    if(this->BulletDirection=="f")
    {
        this->BulletShape.setPosition(x + width - 5 ,y +height/2 );
    }
    else if(this->BulletDirection=="r")
    {
        this->BulletShape.setPosition(x + width/2 ,y + height/2 - 15);
    }
    else if(this->BulletDirection=="l")
    {
        this->BulletShape.setPosition(x + width/2 ,y +height/2 + 12);
    }
    else if(this->BulletDirection=="b")
    {
        this->BulletShape.setPosition(x + width/2 - 17,y +height/2 );
    }
}
void Bullets::setDirection() {
    if(this->BulletDirection=="f")
    {
        this->direction.x=0.f;
        this->direction.y=1.f;
        this->BulletShape.rotate(90);
    }
    else if(this->BulletDirection=="r")
    {
        this->direction.x=1.f;
        this->direction.y=0.f;
    }
    else if(this->BulletDirection=="l")
    {
        this->direction.x=-1.f;
        this->direction.y=0.f;
        this->BulletShape.rotate(180);
    }
    else if(this->BulletDirection=="b")
    {
        this->direction.x=0.f;
        this->direction.y=-1.f;
        this->BulletShape.rotate(270);
    }
}

//<------------ UPDATE FUNCTIONS ------------>
void Bullets::update()
{
    //movement
    this->BulletShape.move(this->movementSpeed * this->direction);
}

//<------------ RENDER FUNCTIONS ------------>
void Bullets::render(sf::RenderTarget* target)
{
    target->draw(this->BulletShape);

}


