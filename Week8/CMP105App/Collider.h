#pragma once
#include "Framework/GameObject.h"
class Collider:public GameObject
{
public:
	Collider();
	~Collider();

	void setWindow(sf::RenderWindow* win) { window = win; };

	virtual void update(float dt);
	
	void collisionResponse(GameObject* collider);

protected:
	sf::RenderWindow* window;
};

