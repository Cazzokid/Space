#include <SFML/Graphics.hpp>
#include <iostream>
#include "projectile.hpp"
#include "VectorMath.hpp"

// Also inherits from sceneobject, baseclass for everything that 'shoots'. 
// this is the baseclass for the missile and meteor.
// projectile in itselt does not draw anything. it is only used to calculate the position of the missile and meteor.

Projectile::Projectile(const sf::Vector2f& begin, const sf::Vector2f& target, float speed)
    : SceneObject(begin)
{
    // set the speed of the projectile. Thinking I want the missiles to possibly be faster than the meteors.
    this->m_speed = speed;
    this->m_target = target;
    // set the direction of the projectile.
    this->m_begin = normalize(target - begin);
    this->m_begin = begin;
}

Projectile::~Projectile()
{

}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

bool Projectile::update(const sf::Time& delta)
{
    return true;
}
