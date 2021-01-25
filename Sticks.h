//
// Created by Mishal Zulfiqar on 24/01/2021.
//
#include <SFML/Graphics.hpp>

#ifndef DSAGAME_STICKS_H
#define DSAGAME_STICKS_H

class Sticks {

private:

    //sprite
    sf::Sprite stickSprite;
    sf::Texture stickTexture;

    //bool that shows they are currently in open state or closed state
    bool Open;

public:
    //constructors and destructors
    Sticks(float x, float y);
    virtual ~Sticks();

    //initialing functions
    void initSprite(float x, float y);

    //setters and getters
    sf::FloatRect getBounds();
    void setPosition(float x, float y);
    bool isOpen();
    void setOpen(bool cond);

    //render functions
    void renderStick(sf::RenderWindow* target);
};


#endif //DSAGAME_STICKS_H
