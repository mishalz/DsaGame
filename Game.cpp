
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

    this->captives.push_back(new Captives(sf::Vector2f(1200.f,50.f),1));
    this->captives.push_back(new Captives(sf::Vector2f(1230.f,70.f),2));

}
void Game::initHealthBar()
{
    //init player health
    this->playerHpBar.setSize(sf::Vector2f(100.f,25.f));
    this->playerHpBar.setFillColor(sf::Color::Green);
    this->playerHpBar.setPosition(sf::Vector2f(400.f,12.f));

    this->playerHpBarBack=this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25,25,25,200));

}
void Game::initSticks()
{
    this->sticks.push_back(new Sticks(1265.f,170.f));

}
void Game::initPlayer() {
    this->mainPlayer=new Player();
    this->PlayerDirection="f";
}

void Game::initEnemy() {
    this->enemies.push_back(new Enemy(sf::Vector2f(100.f,65.f),sf::Vector2f(500.f,65.f),1.f));
}
void Game::initText()
{
    //load fonts
    if(!this->ScoreFont.loadFromFile("Fonts/GrandHotel-Regular.otf"))
    {
        std::cout <<"Failed to load font. \n";
    }

    //init point text
    this->ScoreText.setFont(this->ScoreFont);
    this->ScoreText.setCharacterSize(35);
    this->ScoreText.setFillColor(sf::Color::White);
    this->ScoreText.setString("None");
    this->ScoreText.setPosition(50.f,0.f);
    this->HealthText.setFont(this->ScoreFont);
    this->HealthText.setCharacterSize(35);
    this->HealthText.setFillColor(sf::Color::White);
    this->HealthText.setString("Health: ");
    this->HealthText.setPosition(300.f,0.f);
}
void Game::initStack()
{
    this->CaptiveStack=new Stack(this->captives.size());
};
void Game::initBlocks() {
    //upper side border of blocks
    float x=0.f;float y=0.f;
    while(x<1400) {
        blocksArray.push_back(new Blocks(x, y,0.f));
        x=x+70;
    }

    //left side border of blocks
    x=0.f;
    y=850.f;
    while(y>160) {
        blocksArray.push_back(new Blocks(x, y,0.f));
        y=y-45;
    }

    //bottom side border of blocks
    x=70.f;y=802.f;
    while(x<1500) {
        blocksArray.push_back(new Blocks(x, y,0.f));
        x=x+70;
    }

    //right side border of blocks
    x=1330.f;y=670.f;
    while(y>30) {
        blocksArray.push_back(new Blocks(x, y,0.f));
        y=y-45;
    }

    //l shaped blocks upper left side
    blocksArray.push_back(new Blocks(150, 330,0.f));
    blocksArray.push_back(new Blocks(220, 330,0.f));
    blocksArray.push_back(new Blocks(290, 330,0.f));
    blocksArray.push_back(new Blocks(150, 295,0.f));
    blocksArray.push_back(new Blocks(150, 250,0.f));
    blocksArray.push_back(new Blocks(150, 205,0.f));
    blocksArray.push_back(new Blocks(150, 160,0.f));
    blocksArray.push_back(new Blocks(150, 130,0.f));

    //captive block upper right side
    blocksArray.push_back(new Blocks(1130, 145,0.f));
    blocksArray.push_back(new Blocks(1195, 145,0.f));
    blocksArray.push_back(new Blocks(1130, 100,0.f));
    blocksArray.push_back(new Blocks(1130, 55,0.f));

    //title l besides the captive block on upper right side
    blocksArray.push_back(new Blocks(1260, 280,0.f));
    blocksArray.push_back(new Blocks(1190, 280,0.f));
    blocksArray.push_back(new Blocks(1120, 280,0.f));
    blocksArray.push_back(new Blocks(1050, 280,0.f));

    blocksArray.push_back(new Blocks(980, 280,0.f));
    blocksArray.push_back(new Blocks(980, 225,0.f));
    blocksArray.push_back(new Blocks(980, 180,0.f));
    blocksArray.push_back(new Blocks(980, 135,0.f));

    // |
    blocksArray.push_back(new Blocks(840, 410,0.f));
    blocksArray.push_back(new Blocks(840, 355,0.f));
    blocksArray.push_back(new Blocks(840, 310,0.f));
    blocksArray.push_back(new Blocks(840, 265,0.f));
    blocksArray.push_back(new Blocks(840, 220,0.f));
    blocksArray.push_back(new Blocks(840, 175,0.f));
    blocksArray.push_back(new Blocks(840, 130,0.f));

    // --
    blocksArray.push_back(new Blocks(910, 410,0.f));
    blocksArray.push_back(new Blocks(980, 410,0.f));
    blocksArray.push_back(new Blocks(1050, 410,0.f));

    //|
    blocksArray.push_back(new Blocks(1190, 590,0.f));
    blocksArray.push_back(new Blocks(1190, 545,0.f));
    blocksArray.push_back(new Blocks(1190, 500,0.f));
    blocksArray.push_back(new Blocks(1190, 455,0.f));
    blocksArray.push_back(new Blocks(1190, 410,0.f));

    //straight block line lower left side
    blocksArray.push_back(new Blocks(210, 460,0.f));
    blocksArray.push_back(new Blocks(140, 460,0.f));
    blocksArray.push_back(new Blocks(70, 460,0.f));

    //captive block middle side next to the two l's
    blocksArray.push_back(new Blocks(560,330,0.f));
    blocksArray.push_back(new Blocks(490,330,0.f));
    blocksArray.push_back(new Blocks(420,330,0.f));

    blocksArray.push_back(new Blocks(350,330,0.f));

    //left side of the block extending down
    blocksArray.push_back(new Blocks(350,675,0.f));
    blocksArray.push_back(new Blocks(350,625,0.f));
    blocksArray.push_back(new Blocks(350,575,0.f));
    blocksArray.push_back(new Blocks(350,530,0.f));

    blocksArray.push_back(new Blocks(350,475,0.f));
    blocksArray.push_back(new Blocks(350,425,0.f));
    blocksArray.push_back(new Blocks(350,385,0.f));

    blocksArray.push_back(new Blocks(420,475,0.f));
    //space
    blocksArray.push_back(new Blocks(560,475,0.f));
    blocksArray.push_back(new Blocks(560,425,0.f));
    blocksArray.push_back(new Blocks(560,385,0.f));
    blocksArray.push_back(new Blocks(560,330,0.f));

    //line blocks in the bottom left columns
    blocksArray.push_back(new Blocks(280,675,0.f));
    blocksArray.push_back(new Blocks(210,675,0.f));
    blocksArray.push_back(new Blocks(140,675,0.f));

    blocksArray.push_back(new Blocks(140,625,0.f));
    blocksArray.push_back(new Blocks(140,585,0.f));

}
void Game::initBackgroundSprite() {
    this->backgroundSprite.setTexture(this->backgroundTexture);

}
void Game::initBackgroundTexture() {
    this->backgroundTexture.loadFromFile("Textures/backgroundSprite.png");
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
    this->updateStickPlayerCollision();
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
        if (enemy->getBounds().intersects(this->mainPlayer->getGlobalBounds())) {
            this->mainPlayer->looseHp(1);
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

    if(cond) {

        this->updateStickPlayerCollision();

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
    for(size_t k=0; k<this->sticks.size();k++)
    {

        if(this->sticks[k]->getBounds().intersects(this->mainPlayer->getGlobalBounds()))
        {
            this->mainPlayer->setVelocity(sf::Vector2f(this->mainPlayer->getVelocity().x,0.f));
            this->mainPlayer->setPosition(this->mainPlayer->getGlobalBounds().left, this->sticks[k]->getBounds().top + this->sticks[k]->getBounds().height);

        }

        bool stick_deleted=false;
        for(size_t i=0; i<this->bullets.size() && !stick_deleted;i++)
        {
            if(this->sticks[k]->getBounds().intersects(this->bullets[i]->getBounds()))
            {
                delete this->bullets[i];
                this->bullets.erase(this->bullets.begin()+i);

                delete this->sticks[k];
                this->sticks.erase(this->sticks.begin()+k);
                stick_deleted=true;

            }
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
    this->renderSticks(this->gameWindow);
    this->mainPlayer->PlayerRender(*this->gameWindow);
    this->renderBullets(this->gameWindow);
    this->renderEnemies(this->gameWindow);
    this->renderCaptives(this->gameWindow);
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





















