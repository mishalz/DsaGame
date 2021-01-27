
#include "Game.h"

//<----------------- CONSTRUCTORS AND DESTRUCTORS ----------------->
/* constructing the game object and also deleting it */

Game::Game() {

    //calling all init functions

    this->initWindow();
    this->initTime();
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
    this->initWinningLine();

}

Game::~Game() {
    delete this->gameWindow;
    delete this->mainPlayer;

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
    this->updatedTime=0.f;
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
    this->captives.push_back(new Captives(this->CaptivePositionsMap[4],4));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[5],5));
    this->captives.push_back(new Captives(this->CaptivePositionsMap[6],6));

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
    this->sticks.push_back(new Sticks(1310.f,77.f,0.166f,0.18f));
    this->sticks.push_back(new Sticks(86.f,155.f,0.16f,0.17f));
    this->sticks.push_back(new Sticks(1078.f,245.f,0.185f,0.19f));
    this->sticks.push_back(new Sticks(245.f,735.f,0.19f,0.19f));
    this->sticks.push_back(new Sticks(1036.f,568.f,0.195f,0.19f));
    this->sticks.push_back(new Sticks(715.f,176.f,0.165f,0.19f,90.f));

}
void Game::initPlayer() {
    this->mainPlayer=new Player();
    this->PlayerDirection="f";
}

void Game::initEnemy() {
    this->enemies.push_back(new Enemy(sf::Vector2f(300.f,27.f),
                                      sf::Vector2f(600.f,27.f),0.04,0.04,1.5f));
    this->enemies.push_back(new Enemy(sf::Vector2f(1000.f,770.f),
                                      sf::Vector2f(1350.f,770.f),0.05,0.05,2.0f));
    this->enemies.push_back(new Enemy(sf::Vector2f(140.f,495.f),
                                      sf::Vector2f(370.f,495.f),0.045,0.045,1.0f));
    this->enemies.push_back(new Enemy(sf::Vector2f(980.f,340.f),
                                      sf::Vector2f(1300.f,340.f),0.045,0.045,1.0f));
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
    if(!this->ScoreFont.loadFromFile("Fonts/OpenSans-Bold.ttf"))
    {
        std::cout <<"Failed to load font. \n";
    }

    //init point text
    this->ScoreText.setFont(this->ScoreFont);
    this->ScoreText.setCharacterSize(20);
    this->ScoreText.setFillColor(sf::Color::White);
    this->ScoreText.setString("None");
    this->ScoreText.setPosition(50.f,0.f);

    //init health text
    this->HealthText.setFont(this->ScoreFont);
    this->HealthText.setCharacterSize(20);
    this->HealthText.setFillColor(sf::Color::White);
    this->HealthText.setString("Health: ");
    this->HealthText.setPosition(320.f,0.f);

    //init time text
    this->TimeText.setFont(this->ScoreFont);
    this->TimeText.setCharacterSize(20);
    this->TimeText.setFillColor(sf::Color::White);
    this->TimeText.setString("Time: ");
    this->TimeText.setPosition(680.f,0.f);
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
void Game::initTime()
{
    this->startTime= clock();
}
void Game::initWinningLine()
{
    this->winningLine.setSize(sf::Vector2f(10.f,61.f));
    this->winningLine.setFillColor(sf::Color(180,180,180,180));
    this->winningLine.setPosition(sf::Vector2f(1390.f,766.f));
}

void Game::initBlocks()
{
    for(int row=0; row < 85 ; row+=1)
    {
        for(int col=0; col<140 ; col +=1)
        {
            if(this->MazeStructure[row][col]==1)
            {
                blocksArray.push_back(new Blocks(col*10, row*10, 0.f));
            }
        }
    }
}


//<---------------------- UPDATE FUNCTIONS ---------------------->
/* updating values on the basis of events from the last frame */

void Game::update() {
    this->updateTime();
    this->updateTimeText();
    this->updateMovement();
    this->updateBullets();
    this->mainPlayer->PlayerUpdate();
    this->updateCollision();
    this->updateCaptivePlayerCollision();
    this->updateEnemyMovement();
    this->updateEnemyCollision();
    this->updateEnemyBulletCollision();
    this->updateEnemy();
    this->updateHealthBar();
    this->updateScoreText();
    this->updatePlayerWinningLineCollision();
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
void Game::updateTimeText()
{
    std::stringstream ss;
    ss << "Time: " << std::fixed<<std::setprecision(2)<< this->updatedTime;
    this->TimeText.setString(ss.str());
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
void Game::updatePlayerWinningLineCollision() {

    if(this->mainPlayer->getGlobalBounds().intersects(this->winningLine.getGlobalBounds()))
    {
        reachedFinishLine=true;
        this->mainPlayer->setTimetaken(float(clock()-this->startTime)/CLOCKS_PER_SEC);
    }
}

void Game::updateTime()
{
    this->updatedTime= float (clock()-startTime) / CLOCKS_PER_SEC;
}
//<----------------------------------- RENDER FUNCTIONS ----------------------------------->
/* Render the newly updated values onto the window to display for the current frame */

void Game::render() {

    //clearing the previous frame
    this->gameWindow->clear();

    //drawing all the stuff her
    this->renderBackgroundSprite(this->gameWindow);
    this->renderBlocks(this->gameWindow);
    this->renderTime(this->gameWindow);
    this->mainPlayer->PlayerRender(*this->gameWindow);
    this->renderBullets(this->gameWindow);
    this->renderSticks(this->gameWindow);
    this->renderEnemies(this->gameWindow);
    this->renderCaptives(this->gameWindow);
    this->renderSavedCaptives(this->gameWindow);
    this->renderHealthBar(this->gameWindow);
    this->renderScoreText(this->gameWindow);
    this->renderWinningLine(this->gameWindow);

    //this->renderEnemyHealthBar(this->gameWindow);

    //displaying the window
    this->gameWindow->display();

    if(this->reachedFinishLine)
    {

    }
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
        savedCaptive->setPosition(sf::Vector2f(950.f + (25.f*counter),0.f));
        savedCaptive->setScale(0.05f,0.05f);
        savedCaptive->renderCaptive(target);
        counter++;
    }

}
void Game::renderTime(sf::RenderWindow *target)
{
    target->draw(this->TimeText);
}
void Game::renderWinningLine(sf::RenderWindow* target)
{
    target->draw(this->winningLine);
}

//<---------------------- GETTERS AND SETTERS ---------------------->

sf::RenderWindow *Game::getWindow() {
    return this->gameWindow;
}
/*int* Game::getMazeStructure() {
    for(int row=0; row < 850 ; row+=10)
    {
        for(int col=0; col<1400 ; col +=10)
        {
            for(auto &block:this->blocksArray)
            {
                if(block->getGlobalBounds().contains(col,row))
                {
                    this->MazeStructure[row][col]=1;
                    break;
                }
                else{
                    this->MazeStructure[row][col]=0;
                }
            }
        }
    }

    for(int row=0; row < 850 ; row+=10)
    {
        std::cout << "{ ";
        for(int col=0; col<1400 ; col +=10)
        {
            std::cout << this->MazeStructure[row][col] << ", ";
        }
        std::cout << "}, "<< std::endl;
    }

}*/
//<---------------------- RUN FUNCTION ---------------------->
/* The main run function that includes the game loop and calls the three main functions for each frame */

void Game::runGame() {

        /***** three parts of the game ******
         * - listen for events (poll events)
         * - update all values for the new frame (update)
         * - render the updated values to the screen (render) */

        this->updatePollEvents();

        if(this->mainPlayer->getHp() >0 && !this->reachedFinishLine) {
            this->update();
        }

        this->render();
}

























