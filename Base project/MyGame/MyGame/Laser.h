#pragma once

#include "Engine/GameEngine.h"

class Laser : public GameObject
{
public:

	//Creates Laster
	Laser(sf::Vector2f pos);

	// Functions overrideen from GameObject:
	void draw();
	void update(sf::Time& Elapsed);
	sf::FloatRect getCollisionRect();

private:
	sf::Sprite sprite_;

};

typedef std::shared_ptr<Laser> LaserPtr;


