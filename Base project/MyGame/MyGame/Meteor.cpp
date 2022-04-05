#include "Meteor.h"
#include "Explosion.h"

const float SPEED = 0.25f;

sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}

	makeDead();
	ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
	GAME.getCurrentScene().addGameObject(explosion);
}

Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}

// STOPPED AT Part 8: Sound Effects
// https://github.com/MichaelTMiyoshi/WilliamsGameEngineVS2019/blob/master/Game%20Engine%20Tutorial.pdf