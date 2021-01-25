//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#ifndef DSAGAME_BULLETS_H
#define DSAGAME_BULLETS_H


class Bullets {

private:
    sf::Sprite BulletShape;
    sf::Texture BulletTexture;

    sf::Vector2f direction;
    float movementSpeed;

    std::string BulletDirection;

public:
    //constructors and destructors
    Bullets();
    Bullets(float pos_x, float pos_y, float width, float height, float mSpeed, std::string direction);
    virtual ~Bullets();

    //getters and setters
    const sf::FloatRect getBounds() const;
    float getWidth();
    void setPos(float x, float y,float width, float height);
    void setDirection();
    void update();
    void render(sf::RenderTarget* target);
};


#endif //DSAGAME_BULLETS_H
