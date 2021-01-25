//
// this class serves as the handler of our main character player
// and all the functionality related to the main player
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef DSAGAME_PLAYER_H
#define DSAGAME_PLAYER_H

class Player {

private:

    //sprite for the player
    sf::Sprite PlayerSprite;
    //texture for the sprite
    sf::Texture PlayerTexture;

    //speed of movement of the player
    float movementSpeed;
    sf::Vector2f velocity;

    //Bullet settings
    float attackCoolDown;
    float attackCoolDownMax;

    //health of the player
    int hp;
    int hpMax;

public:

    //constructors and destructors
    Player();
    virtual ~Player();

    //initializing functions
    void initPlayerTexture();
    void initPlayerSprite();
    void initVariables();

    //update functions
    void PlayerUpdate();
    void updateAttack();

    //render function
    void PlayerRender(sf::RenderTarget& target);

    //getters and setters
    void setSpriteTexture(std::string texturePath);
    sf::FloatRect getGlobalBounds();
    void setPosition(float x, float y);
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f vec);
    float getMovementSpeed();
    const int& getHp() const;
    const int& getHpMax() const;
    void setHp(int hp);
    void looseHp(int value);
    sf::Vector2f getPos();

    //Other function
    void move();
    const bool canAttack();

};

#endif //DSAGAME_PLAYER_H
