//
// this class serves as the handler of our main character player
// and all the functionality related to the main player
//

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <time.h>

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

    //time that the player takes to reach to the end
    float timeTaken;

    //Bullet settings
    float attackCoolDown;
    float attackCoolDownMax;

    //captive settings
    float enemyCollisionCoolDown;
    float enemyCollisionCoolDownMax;

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
    void updateCollisionCooldown();

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
    float getTimetaken();
    void setTimetaken(float time);

    //Other function
    void move();
    const bool canAttack();
    const bool canCollide();

};

#endif //DSAGAME_PLAYER_H
