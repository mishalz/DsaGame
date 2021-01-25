//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include <SFML/Graphics.hpp>

#ifndef DSAGAME_CAPTIVES_H
#define DSAGAME_CAPTIVES_H


class Captives {

private:
    //sprite and texture

    sf::Texture captiveTexture;

    //captive id
    int captiveId;

public:
    sf::Sprite captiveSprite;
    //constructors and destructors
    Captives(sf::Vector2f pos,int Id);
    Captives();
    virtual ~Captives();

    //initializing functions
    void initCaptiveSprite(sf::Vector2f pos);
    void initVariables(int Id);

    //setters and getters
    void setPosition(sf::Vector2f pos);
    sf::FloatRect getBounds();
    void setScale(float x, float y);

    //update functions

    //render functions
    void renderCaptive(sf::RenderWindow* target);
};


#endif //DSAGAME_CAPTIVES_H
