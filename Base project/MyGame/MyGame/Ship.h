#pragma once

#include "Engine/GameEngine.h"

class Ship : public GameObject
{
public: 
	// Creates out ship.
	Ship();

	//Functions overrideen from GameObject
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
	int fireTimer_ = 0;

};

typedef std::shared_ptr<Ship> ShipPtr;


// STOPPED RIGHT AFTER MAKING THIS (right after ship.h code)