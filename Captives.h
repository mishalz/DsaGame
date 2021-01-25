//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include <SFML/Graphics.hpp>

#ifndef DSAGAME_CAPTIVES_H
#define DSAGAME_CAPTIVES_H


class Captives {

private:
    //sprite and texture
    sf::Sprite captiveSprite;
    sf::Texture captiveTexture;

public:
    //constructors and destructors
    Captives();
    virtual ~Captives();

    //initializing functions
    void initCaptiveSprite();

    //setters and getters
    void setPosition(sf::Vector2f pos);

    //update functions

    //render functions
    void renderCaptive(sf::RenderWindow* target);
};


#endif //DSAGAME_CAPTIVES_H
