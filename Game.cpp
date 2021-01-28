
#include "Game.h"



//<----------------- CONSTRUCTORS AND DESTRUCTORS ----------------->
/* constructing the game object and also deleting it */

Game::Game() {

    //calling all init functions

    this->initWindow();
    this->initTime();
    this->initVariables();
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

    //deleting block
    for(auto* i: this->blocksArray)
    {
        delete i;
    }
}

//<---------------------- INIT FUNCTIONS ---------------------->
/* separate functions for initializing each element */
void Game::initVariables()
{
    this->endPoints=sf::Vector2f(27.f,14.f);
    this->startPoints=sf::Vector2f(0.f,1.f);
    this->score=0;
    this->updatedTime=0.f;
}
void Game::initWindow() {

    sf::VideoMode videoMode;
    videoMode=sf::VideoMode(1400,800);
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
    this->playerHpBar.setFillColor(sf::Color(115,201,235, 255));
    this->playerHpBar.setPosition(sf::Vector2f(400.f,03.f));

    this->playerHpBarBack=this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25,25,25,200));

}
void Game::initSticks()
{
    this->sticks.push_back(new Sticks(1291.f,85.f,0.152f,0.14f)); //
    this->sticks.push_back(new Sticks(142.f,188.f,0.152f,0.14f)); //
    this->sticks.push_back(new Sticks(943.f,195.f,0.152f,0.14f)); //
    this->sticks.push_back(new Sticks(43.f,690.f,0.152f,0.14f)); //
    this->sticks.push_back(new Sticks(1100.f,493.f,0.152f,0.14f, 90.f));
    this->sticks.push_back(new Sticks(643.f,195.f,0.152f,0.14f)); //
}
void Game::initPlayer() {
    this->mainPlayer=new Player();
    this->PlayerDirection="f";
}

void Game::initEnemy() {
    this->enemies.push_back(new Enemy(sf::Vector2f(400.f,45.f),
                                      sf::Vector2f(700.f,45.f),0.04,0.045,1.5f));
    this->enemies.push_back(new Enemy(sf::Vector2f(200.f,495.f),
                                      sf::Vector2f(410.f,495.f),0.045,0.045,1.0f));
    this->enemies.push_back(new Enemy(sf::Vector2f(1050.f,195.f),
                                      sf::Vector2f(1300.f,195.f),0.045,0.045,1.0f));
}
void Game::initCaptivePositions()
{
    this->CaptivePositionsMap.insert({1, sf::Vector2f(1290.f,45.f)});
    this->CaptivePositionsMap.insert({2, sf::Vector2f(145.f,145.f)});
    this->CaptivePositionsMap.insert({3, sf::Vector2f(940.f,205.f)});
    this->CaptivePositionsMap.insert({4, sf::Vector2f(45.f,700.f)});
    this->CaptivePositionsMap.insert({5, sf::Vector2f(1040.f,505.f)});
    this->CaptivePositionsMap.insert({6, sf::Vector2f(645.f,205.f)});
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
    for(int row=0; row < 16 ; row+=1)
    {
        for(int col=0; col< 28 ; col +=1)
        {
            if(this->MazeStructure[row][col]==1)
            {
                blocksArray.push_back(new Blocks(col* 50, row*50, 0.f));
            }
            else if(this->MazeStructure[row][col]==0)
            {
                this->pathCoordinates.push_back(std::make_pair(col, row));
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

            //bottom collision
            if(playerBounds.top < stickBounds.top
               && playerBounds.top + playerBounds.height < stickBounds.top +stickBounds.height
               && playerBounds.left < stickBounds.left + stickBounds.width
               && playerBounds.left + playerBounds.width > stickBounds.left)
            {
                this->mainPlayer->setVelocity(sf::Vector2f(
                        this->mainPlayer->getVelocity().x,
                        0.f));

                this->mainPlayer->setPosition(playerBounds.left, stickBounds.top - playerBounds.height);
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
    this->renderBlocks(this->gameWindow);
    this->renderTime(this->gameWindow);
    this->mainPlayer->PlayerRender(*this->gameWindow);
    this->renderHealthBar(this->gameWindow);
    this->renderScoreText(this->gameWindow);
    this->renderBullets(this->gameWindow);
    this->renderSticks(this->gameWindow);
    this->renderEnemies(this->gameWindow);
    this->renderCaptives(this->gameWindow);
    this->renderSavedCaptives(this->gameWindow);
    this->renderWinningLine(this->gameWindow);
    this->renderBFSelements(this->gameWindow);

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
        savedCaptive->setPosition(sf::Vector2f(950.f + (35.f*counter),0.f));
        savedCaptive->setScale(0.09f,0.09f);
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
void Game::renderBFSelements(sf::RenderWindow* target)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        this->BFSsearch(this->startPoints.x,this->startPoints.y);
        this->backTracking();

        for(auto &shapes: this->illuminators)
        {
            target->draw(shapes);
        }
    }

}

//<---------------------- GETTERS AND SETTERS ---------------------->

sf::RenderWindow *Game::getWindow() {
    return this->gameWindow;
}
sf::CircleShape Game::getCircleIlluminator(float x, float y)
{
    for(auto &circle : this->illuminators)
    {
        if(circle.getPosition().x==x && circle.getPosition().y==y)
        {
            return circle;
        }
    }

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setRadius(4);
    circle.setPosition(x,y);
    return circle;
}
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

//<--------------- BREADTH FIRST TRAVERSAL AND BACKTRACKING TO FIND OUT THE SHORTEST PATH --------------->
void Game::BFSsearch(float x1, float y2) {

    //inserting the current coordinates into the activeCoordinates list and
    //the solution map
    this->searchedPath=new nodeStructure(x1,y2, nullptr);

    this->activeCoordinates.push_back(this->searchedPath);

    while(!activeCoordinates.empty())
    {
        //dequeueing the activeCoordinates queue
        nodeStructure* currentCoordinates=this->activeCoordinates.back();
        float x=currentCoordinates->x;
        float y=currentCoordinates->y;
        this->activeCoordinates.pop_back();

        //checking if the coordinates on the left are either visited or a wall
        if(existsInPath(x-1, y) && notExistsInVisited(x-1, y))
        {
            //adding the coordinate to the activeCoordinates vector
            this->activeCoordinates.push_back(new nodeStructure(x-1,y,currentCoordinates));
            //also adding those coordinates in the visited coordinates list
            this->visitedCoordinates.emplace_back(std::make_tuple(x-1
                                                                  ,y));
        }

        //checking if the coordinates on the bottom are either visited or a wall
        if(existsInPath(x, y+1) && notExistsInVisited(x, y+1))
        {

            //adding the coordinate to the activeCoordinates vector
            this->activeCoordinates.push_back(new nodeStructure(x,y+1,currentCoordinates));
            //also adding those coordinates in the visited coordinates list
            this->visitedCoordinates.emplace_back(std::make_tuple(x,y+1));
        }

        //checking if the coordinates on the right are either visited or a wall
        if(existsInPath(x+1, y) && notExistsInVisited(x+1, y))
        {

            //adding the coordinate to the activeCoordinates vector
            this->activeCoordinates.push_back(new nodeStructure(x+1,y,currentCoordinates));
            //also adding those coordinates in the visited coordinates list
            this->visitedCoordinates.emplace_back(std::make_tuple(x+1,y));
        }

        //checking if the coordinates on the top are either visited or a wall
        if(existsInPath(x, y-1) && notExistsInVisited(x, y-1))
        {

            //adding the coordinate to the activeCoordinates vector
            this->activeCoordinates.push_back(new nodeStructure(x,y-1,currentCoordinates));
            //also adding those coordinates in the visited coordinates list
            this->visitedCoordinates.emplace_back(std::make_tuple(x,y-1));
        }


        this->illuminators.push_back(getCircleIlluminator(x*50, y*50));

        if(x==27 && y==14)
        {
            this->endOfPath=currentCoordinates;
        }
    }

}

void Game::backTracking()
{
    float x= 27.f;
    float y= 14.f;

    sf::CircleShape temp=getCircleIlluminator(x*50,y*50);
    temp.setFillColor(sf::Color::Yellow);
    this->illuminators.push_back(temp);

    nodeStructure* iter=this->endOfPath;
    nodeStructure* tempPtr;

    while( x != this->startPoints.x || y != this->startPoints.y && iter!= nullptr)
    {
        tempPtr= iter->previous;
        iter= tempPtr;

        x=iter->x;
        y=iter->y;

        temp=getCircleIlluminator(x*50,y*50);
        temp.setFillColor(sf::Color::Yellow);
        this->illuminators.push_back(temp);
    }
}
bool Game::existsInPath(float x, float y) {

    for(auto &pathCo: this->pathCoordinates)
    {
        if(pathCo.first==x && pathCo.second==y)
        {
           return true;
        }
    }
    return false;
}

bool Game::notExistsInVisited(float x, float y) {

    for(auto &pathCo: this->visitedCoordinates)
    {
        if(pathCo.first==x && pathCo.second==y)
        {
            return false;
        }
    }
    return true;
}





























