//
// Created by Mishal Zulfiqar on 22/01/2021.
//

#include <SFML/Graphics.hpp>

#ifndef DSAGAME_BLOCKS_H
#define DSAGAME_BLOCKS_H


class Blocks {

private:

    //block sprite
    sf::Sprite BlockSprite;
    //texture for the block
    sf::Texture BlockTexture;

public:
    //constructors and destructors
    Blocks();
    Blocks(float posX, float posY, float angle);
    virtual ~Blocks();

    //initializing functions
    void initSprite(float posX, float posY, float angle);
    void initTexture();

    //render functions
    void blockRender(sf::RenderTarget* target);

    //other functions
    sf::FloatRect getGlobalBounds();
};

#endif //DSAGAME_BLOCKS_H
