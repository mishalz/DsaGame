//
// Created by Mishal Zulfiqar on 24/01/2021.
//

#include <SFML/Graphics.hpp>

#ifndef DSAGAME_ENEMY_H
#define DSAGAME_ENEMY_H


class Enemy {

private:

    //enemy sprite and texture
    sf::Sprite enemySprite;
    sf::Texture texture;

    float movementSpeed;

    //starting and ending positions of the patrol
    sf::Vector2f startingPos;
    sf::Vector2f EndingPos;

    //health of the player
    int hp;
    int hpMax;

    //health bar of enemy
    sf::RectangleShape enemyHpBar;
    sf::RectangleShape enemyHpBarBack;

public:
    //constructors and destructors
    Enemy(sf::Vector2f startingP, sf::Vector2f EndingPos, float mspeed);
    Enemy();
    virtual ~Enemy();

    //init functions
    void initSprite();
    void initTexture();
    void initVariables();
    void initPositions(sf::Vector2f startingP, sf::Vector2f EndingP);
    void initHealthBar();

    //setters and getters
    void setMovementSpeed(float speed);
    sf::FloatRect getBounds();
    const int& getHp() const;
    const int& getHpMax() const;
    void setHp(int hp);
    void looseHp(int value);

    //update functions
    void update();
    void updateHealthBar();

    //render functions
    void render(sf::RenderWindow* target);
    void renderEnemyHealthBar(sf::RenderWindow *target);

    //move function
    void move(float x, float y);
};


#endif //DSAGAME_ENEMY_H
