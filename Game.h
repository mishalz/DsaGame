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
#include <tuple>
#include <vector>
#include <time.h>
#include "queue"
#include <iostream>
#include <iomanip>

#ifndef DSAGAME_GAME_H
#define DSAGAME_GAME_H

//node struct
struct nodeStructure
{
    float x;
    float y;
    nodeStructure* previous;

    nodeStructure(){}
    nodeStructure(float x1, float y1, nodeStructure* p)
    {
        this->x=x1;
        this->y=y1;
        this->previous=p;
    }
};

class Game {

private:

    //attributes
    sf::RenderWindow* gameWindow;

    //main player object
    Player* mainPlayer;
    std::string PlayerDirection;

    //<-------------- data structures ------------->

    //maze structure
    int MazeStructure[16][28]={
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            { 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
            { 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
            { 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
            { 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
            { 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            { 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
            { 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
            { 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
            { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
            { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
            { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

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

    //for breadth first traversals
    sf::Vector2f endPoints;
    sf::Vector2f startPoints;
    std::vector<sf::CircleShape> illuminators;
    nodeStructure* searchedPath; //linked list for the backtracking path;
    nodeStructure* endOfPath;
    std::vector<std::pair<float, float>> visitedCoordinates;
    std::vector<std::pair<float, float>> pathCoordinates;
    std::vector<nodeStructure*> activeCoordinates;

    //<------- End data structures ------->

    //next position holder of the player
    sf::FloatRect nextPosition;

    //health bar of player
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    //winning line
    sf::RectangleShape winningLine;
    bool reachedFinishLine;

    //score
    unsigned score;

    //texts to display score
    sf::Font ScoreFont;
    sf::Text ScoreText;
    sf::Text HealthText;
    sf::Text TimeText;

    //stop watch
    time_t startTime;
    float updatedTime;

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
    void initTime();
    void initWinningLine();

    //update functions
    void update();
    void updatePollEvents();
    void updateMovement();
    void updateTime();
    void updateBullets();
    void updateEnemy();
    void updateEnemyMovement();
    void updateHealthBar();
    void updateScoreText();
    void updateTimeText();
    void updateCollision();
    void updateBlockCollision();
    void updateEnemyCollision();
    void updateEnemyBulletCollision();
    void updateStickPlayerCollision();
    void updateCaptivePlayerCollision();
    void updatePlayerWinningLineCollision();

    //render functions
    void render();
    void renderTime(sf::RenderWindow *target);
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
    void renderWinningLine(sf::RenderWindow* target);
    void renderBFSelements(sf::RenderWindow* target);

    //setters and getters
    sf::RenderWindow* getWindow();
    sf::CircleShape getCircleIlluminator(float x, float y);
    nodeStructure* getNode(float x, float y);

    //breadth first search
    void BFSsearch(float x, float y);
    void backTracking();
    bool existsInPath(float x, float y);
    bool notExistsInVisited(float x, float y);
    bool DoesnotCrossWallHor(float x1, float y, float x2);
    bool DoesnotCrossWallVer(float y1, float x, float y2);

    //run function
    void runGame();

};


#endif //DSAGAME_GAME_H
