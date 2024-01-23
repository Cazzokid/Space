/*Det måste finnas en egenskapad klass **Tower** som används i spelet.
    - Det ska bara finnas ett torn som kan skjuta missiler.
    - Det ska finnas någon form av "nerkylning" (cooldown) för att avfyra missiler.
    Exempelvis kan det finnas en begränsning på en (1) sekund innan en missil kan avfyras igen.
    Det kan alltså hända att spelaren väljer att avfyra en missil, men inget händer eftersom tornet "kyler ner".
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "tower.hpp"

// Tower inherits from SceneObject, which has the update and draw functions.
// tower is a still object, so it will not move, BLUE RECTANGLE ?
// tower will have a cooldown, 1 second, and if this is still active, it will not shoot.

Tower::Tower(const sf::Vector2f& position) : SceneObject(position)
{
    // set the position of the sprite to the position of the tower.
    this->m_sprite.setPosition(position);
    // using smfl to create a blue rectangle.
	this->m_sprite.setPointCount(4);
	this->m_sprite.setRadius(20.f);
	this->m_sprite.setOrigin(20.f, 20.f);
    this->m_sprite.rotate(45);
	this->m_sprite.setFillColor(sf::Color::Blue);
    // set the cooldown to 1 second.
    this->m_cooldown = sf::seconds(1.0f);
    // set the time since last shot to 0.
    this->m_timeSinceLastShot = sf::Time::Zero;

}

Tower::~Tower()
{

}

// update and draw from sceneobject will be overriden.

bool Tower::update(const sf::Time& delta)
{
	this->m_timeSinceLastShot += delta;
    return true;
}

// Checks if tower can shoot a missile. 
bool Tower::canShoot()
{
    if (this->m_timeSinceLastShot > this->m_cooldown)
    {
        return true;
    }
    return false;
}

void Tower::shoot()
{
	this->m_timeSinceLastShot = sf::Time::Zero;
}


void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // draw the sprite.
    target.draw(this->m_sprite, states);
}
