#pragma once

#include "Engine/GameEngine.h"

class Meteor : public GameObject
{
public:

	//Creates Meteor
	Meteor(sf::Vector2f pos);

	// Functions overrideen from GameObject:
	void draw();
	void update(sf::Time& Elapsed);
private:
	sf::Sprite sprite_;

};

typedef std::shared_ptr<Meteor> MeteorPtr;
