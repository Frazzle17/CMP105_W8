#include "Collider.h"
#include "Framework/Vector.h"
Collider::Collider()
{
	window = nullptr;
}

Collider::~Collider()
{

}

void Collider::update(float dt)
{
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(sf::Vector2f(0, getPosition().y));
		velocity.x *= -1;
	}
	if (getPosition().x > window->getSize().x - getSize().x)
	{
		setPosition(sf::Vector2f(window->getSize().x - getSize().x, getPosition().y));
		velocity.x *= -1;
	}
	if (getPosition().y < 0)
	{
		setPosition(sf::Vector2f(getPosition().x, 0));
		velocity.y *= -1;
	}
	if (getPosition().y > window->getSize().y - getSize().y)
	{
		setPosition(sf::Vector2f(getPosition().x, window->getSize().y - getSize().y));
		velocity.y *= -1;
	}
}

void Collider::collisionResponse(GameObject* collider)
{
	velocity = sf::Vector2f(velocity.x * -1, velocity.y);
}