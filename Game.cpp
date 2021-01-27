
#include "Game.h"

//<----------------- CONSTRUCTORS AND DESTRUCTORS ----------------->
/* constructing the game object and also deleting it */

Game::Game() {

    //calling all init functions

    this->initWindow();
    this->initVariables();
    //background inits
    this->initBackgroundTexture();
    this->initBackgroundSprite();
    //initializing the main player attributes
    this->initPlayer();
    this->initEnemy();
    this->initCaptivePositions();
    this->initCaptives();
    //initializing the blocks array
    this->initBlocks();
    this->initStack();
    this->initSticks();
    this->initHealthBar();
    this->initText();

}

Game::~Game() {
    delete this->gameWindow;
    delete this->mainPlayer;

    //deleting blocks
    for(auto* i: this->blocksArray)
    {
        delete i;
    }

    //deleting bullets
    for(auto* i: this->bullets)
    {
        delete i;
    }

    //deleting enemies
    for(auto* i: this->enemies)
    {
        delete i;
    }

    //deleting captives
    for(auto* i: this->captives)
    {
        delete i;
    }
}

//<---------------------- INIT FUNCTIONS ---------------------->
/* separate functions for initializing each element */

void Game::initVariables()
{
    this->score=0;
}
void Game::initWindow() {

    sf::VideoMode videoMode;
    videoMode=sf::VideoMode(1400,850);
    this->gameWindow= new sf::RenderWindow(videoMode,
                                           "CAPTIVE - EDITION 1",
                                           sf::Style::Close| sf::Style::Titlebar);
    this->gameWindow->setFramerateLimit(40);

}
void Game::initCaptives() {

    this->captives.push_back(new Captives(this->CaptivePositionsMap[1],1));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[2],2));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[3],3));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[4],1));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[5],2));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[6],3));

}
void Game::initHealthBar()
{
    //init player health
    this->playerHpBar.setSize(sf::Vector2f(100.f,20.f));
    this->playerHpBar.setFillColor(sf::Color::Green);
    this->playerHpBar.setPosition(sf::Vector2f(400.f,0.f));

    this->playerHpBarBack=this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25,25,25,200));

}
void Game::initSticks()
{
    this->sticks.push_back(new Sticks(1311.f,75.f,0.166f,0.18f));
    this->sticks.push_back(new Sticks(86.f,155.f,0.16f,0.17f));
    this->sticks.push_back(new Sticks(1080.f,245.f,0.185f,0.19f));
    this->sticks.push_back(new Sticks(240.f,735.f,0.19f,0.19f));
    this->sticks.push_back(new Sticks(1031.f,570.f,0.195f,0.19f));
    this->sticks.push_back(new Sticks(715.f,180.f,0.165f,0.19f,90.f));

}
void Game::initPlayer() {
    this->mainPlayer=new Player();
    this->PlayerDirection="f";
}

void Game::initEnemy() {
    this->enemies.push_back(new Enemy(sf::Vector2f(300.f,25.f),
                                      sf::Vector2f(600.f,25.f),0.04,0.04,1.5f));
    this->enemies.push_back(new Enemy(sf::Vector2f(1000.f,770.f),
                                      sf::Vector2f(1350.f,770.f),0.05,0.05,2.0f));
}
void Game::initCaptivePositions()
{
    this->CaptivePositionsMap.insert({1, sf::Vector2f(1310.f,20.f)});
    this->CaptivePositionsMap.insert({2, sf::Vector2f(80.f,100.f)});
    this->CaptivePositionsMap.insert({3, sf::Vector2f(1085.f,187.f)});
    this->CaptivePositionsMap.insert({4, sf::Vector2f(245.f,674.f)});
    this->CaptivePositionsMap.insert({5, sf::Vector2f(1040.f,505.f)});
    this->CaptivePositionsMap.insert({6, sf::Vector2f(625.f,185.f)});
}
void Game::initText()
{
    //load fonts
    if(!this->ScoreFont.loadFromFile("Fonts/OpenSans-Regular.ttf"))
    {
        std::cout <<"Failed to load font. \n";
    }

    //init point text
    this->ScoreText.setFont(this->ScoreFont);
    this->ScoreText.setCharacterSize(20);
    this->ScoreText.setFillColor(sf::Color::White);
    this->ScoreText.setString("None");
    this->ScoreText.setPosition(50.f,0.f);
    this->HealthText.setFont(this->ScoreFont);
    this->HealthText.setCharacterSize(20);
    this->HealthText.setFillColor(sf::Color::White);
    this->HealthText.setString("Health: ");
    this->HealthText.setPosition(320.f,0.f);
}
void Game::initStack()
{
    this->CaptiveStack=new Stack(this->captives.size());
};
void Game::initBackgroundSprite() {
    this->backgroundSprite.setTexture(this->backgroundTexture);

}
void Game::initBackgroundTexture() {
    this->backgroundTexture.loadFromFile("Textures/backgroundSprite.png");
}
void Game::initBlocks() {
    //upper side border of blocks
    float x = 0.f;
    float y = 0.f;
    while (x < 1400) {
        blocksArray.push_back(new Blocks(x, y, 0.f));
        x = x + 21.5f;
    }

    //left side border of blocks
    x = 0.f;
    y = 850.f;
    while (y > 76) {
        blocksArray.push_back(new Blocks(x, y, 0.f));
        y = y - 21.5f;
    }

    //bottom side border of blocks
    x = 21.5f;
    y = 830.f;
    while (x < 1500) {
        blocksArray.push_back(new Blocks(x, y, 0.f));
        x = x + 21.5f;
    }

    //right side border of blocks
    x = 1380.f;
    y = 745.f;
    while (y > 10) {
        blocksArray.push_back(new Blocks(x, y, 0.f));
        y = y - 21.5f;
    }

    //starting the maze from top left
    //|
    x = 65.f;
    for (y = 79.f; y <= 470.f; y += 21.5f){
    blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=470.f;
    for (x = 65.f; x <= 398.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 410.f;
    for (y = 470.f; y >= 155.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=160.f;
    for (x = 410.f; x <= 494.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 546.f;
    for (y = 79.f; y <= 250.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=240.f;
    for (x = 480.f; x <= 546.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //--
    y=322.f;
    for (x = 420.f; x <= 600.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 613.f;
    for (y = 322.f; y >= 160.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=160.f;
    for (x = 613.f; x <= 780.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //--
    y=245.f;
    for (x = 613.f; x <= 700.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //--
    y=325.f;
    for (x = 780.f; x >= 680.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 680.f;
    for (y = 325.f; y <= 410.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=401.f;
    for (x = 680.f; x >= 480.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 480.f;
    for (y = 401.f; y <= 550.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=480.f;
    for (x = 550.f; x <= 780.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 545.f;
    for (y = 480.f; y <= 720.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=730.f;
    for (x = 545.f; x <= 780.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 780.f;
    for (y = 730.f; y >= 630.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 780.f;
    for (y = 160.f; y <= 480.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=480.f;
    for (x = 780.f; x <= 880.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 940.f;
    for (y = 400.f; y <= 560.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=560.f;
    for (x = 940.f; x >= 680.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 615.f;
    for (y = 560.f; y <= 640.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=640.f;
    for (x = 615.f; x <= 1010.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1010.f;
    for (y = 640.f; y >= 480.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=475.f;
    for (x = 1010.f; x <= 1300.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //captive box bottom right
    //|
    x = 1120.f;
    for (y = 495.f; y <= 560.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 1310.f;
    for (y = 475.f; y >= 390.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }
    blocksArray.push_back(new Blocks(1310.f, 395.f, 0.f));

    //--
    y=560.f;
    for (x = 1310.f; x >= 1184.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1188.f;
    for (y = 560.f; y <= 630.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=640.f;
    for (x = 1188.f; x >= 1100.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //--
    y=645.f;
    for (x = 1260.f; x <= 1400.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //--
    y=733.f;
    for (x = 1100.f; x <= 1300.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1082.f;
    for (y = 640.f; y <= 740.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=733.f;
    for (x = 1082.f; x >= 860.f; x -= 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 860.f;
    for (y = 733.f; y <= 820.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=79.f;
    for (x = 86.f; x <= 134.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 150.f;
    for (y = 79.f; y <= 163.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 215.f;
    for (y = 21.f; y <= 226.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    blocksArray.push_back(new Blocks(215.f, 226.f, 0.f));
    y=226.f;
    for (x = 130.f; x <= 212.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 130.f;
    for (y=226.f; y <= 378.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=385.f;
    for (x = 130.f; x <= 340.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 345.f;
    for (y=385.f; y >= 160.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=79.f;
    for (x = 280.f; x <= 1225.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1225.f;
    for (y=79.f; y <= 150.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=150.f;
    for (x = 1225.f; x <= 1330.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1290.f;
    for (y=64.f; y >= 20.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=235.f;
    for (x = 1180.f; x <= 1330.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1160.f;
    for (y=235.f; y >= 155.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    blocksArray.push_back(new Blocks(1160.f, 160.f, 0.f));

    //--
    y=160.f;
    blocksArray.push_back(new Blocks(280.f, 306.f, 0.f));
    for (x = 1060.f; x <= 1160.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 1060.f;
    for (y=300.f; y >= 155.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    blocksArray.push_back(new Blocks(1060.f, 160.f, 0.f));


    //|
    x = 990.f;
    for (y=235.f; y >= 80.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=315.f;
    for (x = 929.f; x <= 1360.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 922.f;
    for (y=315.f; y >= 150.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 850.f;
    for (y=378.f; y >= 90.f; y -= 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=395.f;
    for (x = 850.f; x <= 1320.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 280.f;
    for (y=100.f; y <= 294.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=306.f;
    blocksArray.push_back(new Blocks(280.f, 306.f, 0.f));
    for (x = 195.f; x <= 279.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //bottom left corner
    //--
    y=550.f;
    for (x = 65.f; x <= 480.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }
    blocksArray.push_back(new Blocks(480.f, 550.f,0.f));

    //|
    x = 65.f;
    for (y=640.f; y <= 820.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 140.f;
    for (y=560.f; y <= 750.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //captive box
    //|
    x = 220.f;
    for (y=640.f; y <= 730.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=640.f;
    blocksArray.push_back(new Blocks(280.f, 306.f, 0.f));
    for (x = 225.f; x <= 530.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 320.f;
    for (y=640.f; y <= 730.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //|
    x = 390.f;
    for (y=725.f; y <= 820.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }

    //--
    y=725.f;
    blocksArray.push_back(new Blocks(280.f, 306.f, 0.f));
    for (x = 390.f; x <= 470.f; x += 21.5f) {
        blocksArray.push_back(new Blocks(x, y,0.f));
    }

    //|
    x = 470.f;
    for (y=725.f; y <= 820.f; y += 21.5f){
        blocksArray.push_back(new Blocks(x, y, 0.f));
    }
}

//<---------------------- UPDATE FUNCTIONS ---------------------->
/* updating values on the basis of events from the last frame */

void Game::update() {
    this->updateMovement();
    this->updateBullets();
    this->mainPlayer->PlayerUpdate();
    this->updateCollision();
    this->updateEnemyMovement();
    this->updateEnemyCollision();
    this->updateEnemyBulletCollision();
    this->updateEnemy();
    this->updateCaptivePlayerCollision();
    this->updateHealthBar();
    this->updateScoreText();
}

//function that listens to events
void Game::updatePollEvents() {

    //poll events
    sf::Event e;
    while(this->gameWindow->pollEvent(e))
    {
        //close the window if escape is pressed or the closed button is clicked
        if(e.Event::type == sf::Event::Closed || (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape))
        {
            this->gameWindow->close();
        }
    }
}

void Game::updateBullets() {
    unsigned counter=0;
    for(auto *bullet:this->bullets)
    {
        bullet->update();
        bool bullet_deleted=false;

        //bullet going out of the screen top
        if(bullet->getBounds().top + bullet->getBounds().height <0.f && !bullet_deleted)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+counter);
            --counter;

        }

        //bullet striking any block
        for(auto *block : this->blocksArray)
        {
            if(bullet->getBounds().intersects(block->getGlobalBounds()) && !bullet_deleted)
            {
                //Delete bullet
                delete this->bullets.at(counter);
                this->bullets.erase(this->bullets.begin()+counter);
                --counter;
                bullet_deleted=true;
            }
        }

        ++counter;
    }
}

void Game::updateEnemyMovement() {

    for(auto &enemy: this->enemies) {
        enemy->move(1.f, 0.f);
    }
}

void Game::updateCollision() {
    if(this->mainPlayer->getGlobalBounds().left <0.f)
    {
        this->mainPlayer->setPosition(0.f,this->mainPlayer->getGlobalBounds().top);
    }
    if(this->mainPlayer->getGlobalBounds().left + this->mainPlayer->getGlobalBounds().width > this->gameWindow->getSize().x)
    {
        this->mainPlayer->setPosition(this->gameWindow->getSize().x-this->mainPlayer->getGlobalBounds().width,this->mainPlayer->getGlobalBounds().top);
    }
    if(this->mainPlayer->getGlobalBounds().top <0.f)
    {
        this->mainPlayer->setPosition(this->mainPlayer->getGlobalBounds().left,0.f);
    }
    if(this->mainPlayer->getGlobalBounds().top + this->mainPlayer->getGlobalBounds().height > this->gameWindow->getSize().y)
    {
        this->mainPlayer->setPosition(this->mainPlayer->getGlobalBounds().left,this->gameWindow->getSize().y-this->mainPlayer->getGlobalBounds().height);
    }
}

void Game::updateBlockCollision() {
    for (auto &bl:this->blocksArray)
    {
        sf::FloatRect playerBounds = this->mainPlayer->getGlobalBounds();
        sf::FloatRect blockBounds = bl->getGlobalBounds();

        this->nextPosition = playerBounds;
        playerBounds.left += this->mainPlayer->getVelocity().x;
        playerBounds.top += this->mainPlayer->getVelocity().y;

        if(blockBounds.intersects(nextPosition))
        {
            //bottom collision
            if(playerBounds.top < blockBounds.top
               && playerBounds.top + playerBounds.height < blockBounds.top +blockBounds.height
               && playerBounds.left < blockBounds.left + blockBounds.width
               && playerBounds.left + playerBounds.width > blockBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, blockBounds.top - playerBounds.height);
            }

            //top collision
            else if(playerBounds.top > blockBounds.top
               && playerBounds.top + playerBounds.height > blockBounds.top +blockBounds.height
               && playerBounds.left < blockBounds.left + blockBounds.width
               && playerBounds.left + playerBounds.width > blockBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, blockBounds.top + blockBounds.height);
            }

            //right collision
            if(playerBounds.left < blockBounds.left
            && playerBounds.left + playerBounds.width < blockBounds.left +blockBounds.width
            && playerBounds.top < blockBounds.top + blockBounds.height
            && playerBounds.top + playerBounds.height > blockBounds.top)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        0.f,
                        this->mainPlayer->getVelocity().y));

                this->mainPlayer->setPosition(blockBounds.left - playerBounds.width, playerBounds.top);
            }
            //left collision
            else if(playerBounds.left > blockBounds.left
               && playerBounds.left + playerBounds.width > blockBounds.left +blockBounds.width
               && playerBounds.top < blockBounds.top + blockBounds.height
               && playerBounds.top + playerBounds.height > blockBounds.top)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        0.f,
                        this->mainPlayer->getVelocity().y));

                this->mainPlayer->setPosition(blockBounds.left + blockBounds.width, playerBounds.top);
            }
        }
    }
}
void Game::updateEnemyCollision()
{
    for(auto &enemy : this->enemies) {

        sf::FloatRect playerBounds = this->mainPlayer->getGlobalBounds();
        sf::FloatRect enemyBounds = enemy->getBounds();

        if (enemyBounds.intersects(playerBounds)) {

            if(this->savedCaptives.size()==0)
            {
                this->mainPlayer->looseHp(1);
            }
            else if(this->mainPlayer->canCollide()){
                this->captives.push_back(this->savedCaptives.back());
                this->savedCaptives.back()->setScale(0.1f,0.1f);
                this->savedCaptives.back()->setPosition(this->CaptivePositionsMap[this->savedCaptives.back()->getId()]);
                this->savedCaptives.pop_back();
            }

            this->nextPosition = playerBounds;
            playerBounds.left += this->mainPlayer->getVelocity().x;
            playerBounds.top += this->mainPlayer->getVelocity().y;

            //bottom collision
            if(playerBounds.top < enemyBounds.top
               && playerBounds.top + playerBounds.height < enemyBounds.top +enemyBounds.height
               && playerBounds.left < enemyBounds.left + enemyBounds.width
               && playerBounds.left + playerBounds.width > enemyBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, enemyBounds.top - playerBounds.height);
            }

                //top collision
            else if(playerBounds.top > enemyBounds.top
                    && playerBounds.top + playerBounds.height > enemyBounds.top +enemyBounds.height
                    && playerBounds.left < enemyBounds.left + enemyBounds.width
                    && playerBounds.left + playerBounds.width > enemyBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, enemyBounds.top + enemyBounds.height);
            }

            //right collision
            if(playerBounds.left < enemyBounds.left
               && playerBounds.left + playerBounds.width < enemyBounds.left +enemyBounds.width
               && playerBounds.top < enemyBounds.top + enemyBounds.height
               && playerBounds.top + playerBounds.height > enemyBounds.top)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        0.f,
                        this->mainPlayer->getVelocity().y));

                this->mainPlayer->setPosition(enemyBounds.left - playerBounds.width, playerBounds.top);
            }
                //left collision
            else if(playerBounds.left > enemyBounds.left
                    && playerBounds.left + playerBounds.width > enemyBounds.left +enemyBounds.width
                    && playerBounds.top < enemyBounds.top + enemyBounds.height
                    && playerBounds.top + playerBounds.height > enemyBounds.top)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        0.f,
                        this->mainPlayer->getVelocity().y));

                this->mainPlayer->setPosition(enemyBounds.left + enemyBounds.width, playerBounds.top);
            }

        }
    }
}
void Game::updateEnemyBulletCollision() {

    for(int i=0; i< enemies.size(); i++)
    {
        bool enemy_deleted=false;
        for(size_t k=0; k<this->bullets.size() && !enemy_deleted;k++)
        {

            if(this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
            {
                this->score += 10;

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin()+k);

                enemies[i]->looseHp(1);
                float hpPercent = static_cast<float>(enemies[i]->getHp())/ enemies[i]->getHpMax();

                if(hpPercent==0)
                {
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin()+i);
                    enemy_deleted=true;
                }

            }
        }

    }


}
void Game::updateHealthBar()
{
    float hpPercent = static_cast<float>(this->mainPlayer->getHp())/ this->mainPlayer->getHpMax();
    this->playerHpBar.setSize(sf::Vector2f(100 * hpPercent, this->playerHpBar.getSize().y));
    if(hpPercent < 0.25)
    {
        this->playerHpBar.setFillColor(sf::Color::Red);
    }

}
void Game::updateMovement() {

    std::string texture1;
    bool cond=true;

    this->mainPlayer->setVelocity(sf::Vector2f(0.f,0.f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down ) ) {
        texture1 = "Textures/PlayerSpriteFront1.png";
        this->mainPlayer->setVelocity(sf::Vector2f(
                0.f,
                this->mainPlayer->getVelocity().y+(this->mainPlayer->getMovementSpeed() * dt)));
        this->PlayerDirection="f";

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        texture1 = "Textures/PlayerSpriteRight3.png";
        this->mainPlayer->setVelocity(sf::Vector2f(
                this->mainPlayer->getVelocity().x+(this->mainPlayer->getMovementSpeed() * dt),
                0.f));
        this->PlayerDirection="r";

    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
        texture1 = "Textures/PlayerSpriteLeft3.png";
        this->mainPlayer->setVelocity(sf::Vector2f(
                this->mainPlayer->getVelocity().x+(-this->mainPlayer->getMovementSpeed() * dt),
                0.f));
        this->PlayerDirection="l";

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        texture1 = "Textures/PlayerSpriteBack3.png";
        this->mainPlayer->setVelocity(sf::Vector2f(
                0.f,
                this->mainPlayer->getVelocity().y+(-this->mainPlayer->getMovementSpeed() * dt)));
        this->PlayerDirection="b";
    }
    else{
        this->mainPlayer->PlayerRender(*this->gameWindow);
        cond=false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->mainPlayer->canAttack())
    {
        this->bullets.push_back(new Bullets(this->mainPlayer->getPos().x,this->mainPlayer->getPos().y, this->mainPlayer->getGlobalBounds().width, this->mainPlayer->getGlobalBounds().height,5.f,this->PlayerDirection));
    }

    this->updateStickPlayerCollision();
    if(cond) {

        this->updateBlockCollision();

        this->renderPlayerMovementDirection(texture1);
    }
}
void Game::updateScoreText()
{
    std::stringstream ss;
    ss << "Points: " << this->score;
    this->ScoreText.setString(ss.str());
}
void Game::updateEnemy() {
    for(auto &enemy : this->enemies)
    {
        enemy->update();
    }
}
void Game::updateStickPlayerCollision() {
    for(size_t k=0; k<this->sticks.size();k++) {

        if (this->sticks[k]->getBounds().intersects(this->mainPlayer->getGlobalBounds())) {

            sf::FloatRect playerBounds=this->mainPlayer->getGlobalBounds();
            sf::FloatRect stickBounds=this->sticks[k]->getBounds();
                //top collision
             if(playerBounds.top > stickBounds.top
                    && playerBounds.top + playerBounds.height > stickBounds.top +stickBounds.height
                    && playerBounds.left < stickBounds.left + stickBounds.width
                    && playerBounds.left + playerBounds.width > stickBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, stickBounds.top + stickBounds.height);
            }

                //left collision
            else if(playerBounds.left > stickBounds.left
                    && playerBounds.left + playerBounds.width > stickBounds.left +stickBounds.width
                    && playerBounds.top < stickBounds.top + stickBounds.height
                    && playerBounds.top + playerBounds.height > stickBounds.top)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        0.f,
                        this->mainPlayer->getVelocity().y));

                this->mainPlayer->setPosition(stickBounds.left + stickBounds.width, playerBounds.top);
            }
        }
    }


    for(size_t k=0; k<this->sticks.size();k++) {

        bool stick_deleted=false;
        for (size_t i = 0; i < this->bullets.size() && !stick_deleted; i++) {

            if (this->sticks[k]->getBounds().intersects(this->bullets[i]->getBounds())) {
                delete this->bullets[i];
                this->bullets.erase(this->bullets.begin() + i);

                delete this->sticks[k];
                this->sticks.erase(this->sticks.begin() + k);
                stick_deleted=true;
            }
        }
    }
}
void Game::updateCaptivePlayerCollision()
{
    for(size_t k=0; k <this->captives.size();k++)
    {
        if(this->captives[k]->getBounds().intersects(this->mainPlayer->getGlobalBounds()))
        {
            //since it has been saved adding it to the stack
            this->CaptiveStack->Push(this->captives[k]);

            this->savedCaptives.push_back(this->captives[k]);
            this->score+=50;

            //then deleting that from the captives vector
            this->captives.erase(this->captives.begin()+k);

        }
    }

}
//<----------------------------------- RENDER FUNCTIONS ----------------------------------->
/* Render the newly updated values onto the window to display for the current frame */

void Game::render() {

    //clearing the previous frame
    this->gameWindow->clear();

    //drawing all the stuff her
    this->renderBackgroundSprite(this->gameWindow);
    this->renderBlocks(this->gameWindow);
    this->mainPlayer->PlayerRender(*this->gameWindow);
    this->renderBullets(this->gameWindow);
    this->renderSticks(this->gameWindow);
    this->renderEnemies(this->gameWindow);
    this->renderCaptives(this->gameWindow);
    this->renderSavedCaptives(this->gameWindow);
    this->renderHealthBar(this->gameWindow);
    this->renderScoreText(this->gameWindow);

    //this->renderEnemyHealthBar(this->gameWindow);

    //displaying the window
    this->gameWindow->display();
}
void Game::renderCaptives(sf::RenderWindow *target){
    for(auto &captive: this->captives){
        captive->renderCaptive(this->gameWindow);
    }
}
void Game::renderSticks(sf::RenderWindow *target)
{
    for(auto &stick: this->sticks)
    {
        stick->renderStick(target);
    }
}
void Game::renderEnemies(sf::RenderWindow *target) {
    for(auto &enemy : this->enemies)
    {
        enemy->render(target);
    }
}
void Game::renderPlayerMovementDirection( std::string texture1) {

    this->mainPlayer->setSpriteTexture(texture1);
    this->mainPlayer->move();
    this->mainPlayer->PlayerRender(*this->gameWindow);
}

void Game::renderBlocks(sf::RenderTarget* target) {

    for(Blocks *block:this->blocksArray)
    {
      block->blockRender(target);
    }
}

void Game::renderBullets(sf::RenderWindow *target)
{
    for(auto *bullet:this->bullets)
    {
        bullet->render(this->gameWindow);
    }
}

void Game::renderBackgroundSprite(sf::RenderTarget* target) {
    for (int x = 0; x <= 1410 ; x+=80) {
        for (int y = 0; y <= 810 ; y+=50) {
            this->backgroundSprite.setPosition(x,y);
            target->draw(this->backgroundSprite);
        }
    }
}
void Game::renderHealthBar(sf::RenderWindow *target)
{

    target->draw(this->HealthText);
    target->draw(this->playerHpBarBack);
    target->draw(this->playerHpBar);
}
void Game::renderScoreText(sf::RenderWindow *target)
{
    target->draw(this->ScoreText);
}
void Game::renderSavedCaptives(sf::RenderWindow *target) {

    int counter=0;
    for(auto &savedCaptive : this->savedCaptives)
    {
        savedCaptive->setPosition(sf::Vector2f(700.f + (25.f*counter),0.f));
        savedCaptive->setScale(0.05f,0.05f);
        savedCaptive->renderCaptive(target);
        counter++;
    }

}
//<---------------------- GETTERS AND SETTERS ---------------------->

sf::RenderWindow *Game::getWindow() {
    return this->gameWindow;
}

//<---------------------- RUN FUNCTION ---------------------->
/* The main run function that includes the game loop and calls the three main functions for each frame */

void Game::runGame() {

        /***** three parts of the game ******
         * - listen for events (poll events)
         * - update all values for the new frame (update)
         * - render the updated values to the screen (render) */

        this->updatePollEvents();

        if(this->mainPlayer->getHp() >0) {
            this->update();
        }

        this->render();
}






















