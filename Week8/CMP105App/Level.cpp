#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");

	ball.setWindow(window);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	ball.setTexture(&ballTexture);
	ball.setVelocity(500, 250);
	ball.setCollisionBox(sf::FloatRect(0, 0, 100, 100));

	square1.setWindow(window);
	square1.setSize(sf::Vector2f(50, 200));
	square1.setPosition(50, 200);
	square1.setFillColor(sf::Color::Red);
	square1.setCollisionBox(sf::FloatRect(0, 0, 50, 200));

	square2.setWindow(window);
	square2.setSize(sf::Vector2f(50, 200));
	square2.setPosition(window->getSize().x - square2.getSize().x - 50, 200);
	square2.setFillColor(sf::Color::Blue);
	square2.setCollisionBox(sf::FloatRect(0, 0, 50, 200));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);

	if (Collision::checkBoundingBox(&square1, &ball) || Collision::checkBoundingBox(&square2, &ball))
	{
		ball.collisionResponse(NULL);
	}
	if (ball.getPosition().x <= 0 || ball.getPosition().x >= window->getSize().x - ball.getSize().x)
	{
		ball.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		square1.setPosition(square1.getPosition().x, square1.getPosition().y + (-500 * dt));
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		square1.setPosition(square1.getPosition().x, square1.getPosition().y + (500 * dt));
	}

	square2.setPosition(square2.getPosition().x, input->getMouseY());
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(square1);
	window->draw(square2);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}