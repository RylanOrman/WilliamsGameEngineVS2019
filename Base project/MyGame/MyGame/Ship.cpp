#include "Ship.h"

#include <memory>
#include "Laser.h"

const float SPEED = 0.3f;
const int FIRE_DELAY = 200;

void Ship::update(sf::Time& elapsed)
{
	sf::Vector2f pos = sprite_.getPosition();
	float x = pos.x;
	float y = pos.y;

	int msElapsed = elapsed.asMilliseconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))	y -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) y += SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= SPEED * msElapsed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += SPEED * msElapsed;

	sprite_.setPosition(sf::Vector2f(x, y));

	if (fireTimer_ > 0)
	{
		fireTimer_ -= msElapsed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
	{
		fireTimer_ = FIRE_DELAY;

		sf::FloatRect bounds = sprite_.getGlobalBounds();

		float laserX = x + bounds.width;
		float laserY = y + (bounds.height / 2.0f);

		LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY));
		GAME.getCurrentScene().addGameObject(laser);

		float laserX1 = x + bounds.width;
		float laserY1 = y + (bounds.height / 3.0f);

		LaserPtr laser1 = std::make_shared<Laser>(sf::Vector2f(laserX1, laserY1));
		GAME.getCurrentScene().addGameObject(laser1);

		float laserX2 = x + bounds.width;
		float laserY2 = y + (bounds.height / 1.5f);

		LaserPtr laser2 = std::make_shared<Laser>(sf::Vector2f(laserX2, laserY2));
		GAME.getCurrentScene().addGameObject(laser2);
		/*
		float laserX3 = x + bounds.width;
		float laserY3 = y + (bounds.height / 1.29f);

		LaserPtr laser3 = std::make_shared<Laser>(sf::Vector2f(laserX3, laserY3));
		GAME.getCurrentScene().addGameObject(laser3);

		float laserX4 = x + bounds.width;
		float laserY4 = y + (bounds.height / 4.5f);

		LaserPtr laser4 = std::make_shared<Laser>(sf::Vector2f(laserX4, laserY4));
		GAME.getCurrentScene().addGameObject(laser4);
		*/
	}

}

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png"));
	sprite_.setPosition(sf::Vector2f(100, 100));
}

void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}