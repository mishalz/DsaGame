//
// This class will handle the main functionality and working of the game
// while serving as an integration platform for all the elements
//

#include "Player.h"
#include "Blocks.h"
#include "Enemy.h"
#include "Captives.h"
#include "Sticks.h"
#include "Bullets.h"
#include "Stack.h"
#include <sstream>
#include <map>

#ifndef DSAGAME_GAME_H
#define DSAGAME_GAME_H


class Game {

private:

    //attributes
    sf::RenderWindow* gameWindow;

    //main player object
    Player* mainPlayer;
    std::string PlayerDirection;

    //<--------- data structures --------->
    //enemy object
    std::vector<Enemy*> enemies;

    //stick objects
    std::vector<Sticks*> sticks;

    //Bullets that the player fires
    std::vector<Bullets*> bullets;

    //array containing all the blocks;
    std::vector<Blocks*> blocksArray;

    //captive objects
    std::vector<Captives*> captives;
    std::vector<Captives*> savedCaptives;

    //stack to store the captives when captured
    Stack* CaptiveStack;

    //map that keeps the value of captive id and its position in the map
    std::map<int, sf::Vector2f> CaptivePositionsMap;
    //<------- End data structures ------->

    //number of captives captured
    int NoOfCaptivesCaptured;

    //background sprite and texture
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;

    //next position holder of the player
    sf::FloatRect nextPosition;

    //health bar of player
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    //score
    unsigned score;

    //texts to display score
    sf::Font ScoreFont;
    sf::Text ScoreText;
    sf::Text HealthText;

public:

    float dt;
    sf::Clock dt_clock;

    //constructors and destructors
    Game();
    virtual ~Game();

    //init functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemy();
    void initCaptivePositions();
    void initCaptives();
    void initSticks();
    void initStack();
    void initBlocks();
    void initBackgroundSprite();
    void initBackgroundTexture();
    void initHealthBar();
    void initText();

    //update functions
    void update();
    void updatePollEvents();
    void updateMovement();
    void updateBullets();
    void updateEnemy();
    void updateEnemyMovement();
    void updateHealthBar();
    void updateScoreText();
    void updateCollision();
    void updateBlockCollision();
    void updateEnemyCollision();
    void updateEnemyBulletCollision();
    void updateStickPlayerCollision();
    void updateCaptivePlayerCollision();

    //render functions
    void render();
    void renderSticks(sf::RenderWindow *target);
    void renderCaptives(sf::RenderWindow *target);
    void renderPlayerMovementDirection( std::string texture1);
    void renderBlocks(sf::RenderTarget* target);
    void renderBackgroundSprite(sf::RenderTarget* target);
    void renderHealthBar(sf::RenderWindow* target);
    void renderScoreText(sf::RenderWindow* target);
    void renderBullets(sf::RenderWindow* target);
    void renderEnemies(sf::RenderWindow* target);
    void renderSavedCaptives(sf::RenderWindow* target);

    //setters and getters
    sf::RenderWindow* getWindow();

    //run function
    void runGame();

};


#endif //DSAGAME_GAME_H
