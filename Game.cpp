#include "Game.h"

//Private Functions
void Game::initVariables()
{
	this->window = nullptr;

	//Initilizes the Game logic stated in <Game.h>
	this->endGame = false;
	this->points = 0;	
	this->health = 15;
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 8;
	this->mouseHeld = false;

}

void Game::initWindow()
{

	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Falling Shapes");
	this->window->setFramerateLimit(60);

}

void Game::initFonts()
{

	if (!this->font.loadFromFile("fonts/SpecialGothicExpandedOne-Regular.ttf"))
	{

		std::cout << "ERROR::GAME::INITFONTS --- Failed to load font!\n";

	}

}

//Sets text object to defined text/font style
void Game::initText()
{

	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);		//Sets font size [12] and default color [white]
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");

}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));

}


//Constructors / Deconstructors
Game::Game()
{ 

	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initEnemies();

}

Game::~Game() 
{

	delete this->window;

}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{

	return this->endGame;

}


//Functions

void Game::spawnEnemies()
{

	/*
		@return void

		Spawns enemies and sets their types, colors, and positions randomly.

		- Sets a random position
		- Sets a random color
		- Adds enemy to the vector.
	
	*/

	//Takes an x and y value -- in this case, y makes sure the shape randomizes at the top of the window
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x) - this->enemy.getSize().x),
		0.f

	);

	// Randomize enemy type

	int type = rand() % 5;

	switch (type) {

		case 0:
			this->enemy.setSize(sf::Vector2f(25.f, 25.f));
			this->enemy.setFillColor(sf::Color::Red);
			break;

		case 1:
			this->enemy.setSize(sf::Vector2f(80.f, 80.f));
			this->enemy.setFillColor(sf::Color::Blue);
			break;

		case 2:
			this->enemy.setSize(sf::Vector2f(100.f, 100.f));
			this->enemy.setFillColor(sf::Color::Magenta);
			break;

		case 3:
			this->enemy.setSize(sf::Vector2f(125.f, 125.f));
			this->enemy.setFillColor(sf::Color::Yellow);
			break;

		case 4:
			this->enemy.setSize(sf::Vector2f(175.f, 175.f));
			this->enemy.setFillColor(sf::Color::Green);
			break;
		
		default: 
			this->enemy.setSize(sf::Vector2f(100.f, 100.f));
			this->enemy.setFillColor(sf::Color::White);
			break;

	}

	//Spawn the enemy
	this->enemies.push_back(this->enemy);
	
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->event)) {

		switch (this->event.type) {

		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

		}

	}

}

void Game::updateMousePositions()
{

	/*
		@ return void 

		updates the mouse positions:
			> Within the game window(Vector2i)
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::updateText()
{
	std::stringstream ss; 

	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->health << "\n";


	this->uiText.setString(ss.str());

}

void Game::updateEnemies()
{
	/*
	
		@return void

		updates the enemy span timer and spawns enemies
		when the total amount of enemies is smaller than the max.

		- Moves the enemies downwards
		- Removes the enemies at the edge of the screen
	*/


	//Updating the timer for enemy spawning
	if (this->enemies.size() < this->maxEnemies) {

		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {

			//spawn the enemy and reset timer
			this->spawnEnemies();
			this->enemySpawnTimer = 0.f;
		}

		else {

			this->enemySpawnTimer += 1.f;

		}

	}
	
	//Moving and updating for enemy spawning	
	for (int i = 0; i < this->enemies.size(); i++) {

		bool deleted = false;
		
		//moves enemy downwards
		this->enemies[i].move(0.f, 3.f);

		//If enemies go beyond "y" bounds of window, marked as deleted
		if (this->enemies[i].getPosition().y > this->window->getSize().y) {

			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "Health: " << this->health << std::endl;

		}
			
		
	}

	//Check if clicked upon	--- also checks/prevents mouse button being held down
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


		if (this->mouseHeld == false) {

			this->mouseHeld = true;

			bool deleted = false;

			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) {

				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView)) {

					//Gains points
					if (this->enemies[i].getFillColor() == sf::Color::Red) {

						this->points += 50.f;

					}

					else if (this->enemies[i].getFillColor() == sf::Color::Blue) {

						this->points += 25.f;


					}

					else if (this->enemies[i].getFillColor() == sf::Color::Magenta) {

						this->points += 15.f;

					}

					else if (this->enemies[i].getFillColor() == sf::Color::Yellow) {

						this->points += 10.f;


					}

					else if (this->enemies[i].getFillColor() == sf::Color::Green) {

						this->points += 5.f;


					}

					std::cout << "Points: " << this->points << std::endl;

					//Deletes enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

				}

			}

		}

	}

	else {

		this->mouseHeld = false;

	}

}

void Game::update(){

	this->pollEvents();

	if (this->endGame == false) {

		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();		

	}	

	//End game condition
	if (this->health <= 0) {

		this->endGame = true;

	}

}

//The target reference allows to draw on other windows 
void Game::renderText(sf::RenderTarget& target)
{

	target.draw(this->uiText);

}

void Game::renderEnemies(sf::RenderTarget& target)
{
	//Rendering all the enemies
	for (auto& e : this->enemies) {

		target.draw(e);

	}

}

void Game::render()
{
	/*
		@return void

		- clear old frame
		- render objects
		- display frame in window 

		Renders the game objects.

	*/

	//Default window is Black
	this->window->clear();

	//Draw game objects  --- the * de-references the window
	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();

}
