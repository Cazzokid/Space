#include "missile.hpp"
#include "VectorMath.hpp"
#include "projectile.hpp"

// inherts from projectile. Sets its own speed, and its own texture.
// thinking this is a 'triangle' missile, red. 
// this will leave a trail behind it, like the firework.

Missile::Missile(const sf::Vector2f& begin, const sf::Vector2f& target, float speed)
    : Projectile(begin, target, speed),
    m_direction(normalize(m_target - m_begin)),
    m_trail(begin, target, sf::Color(50, 50, 50))
{
    this->m_speed = speed;
    this->m_rocketShape.setPointCount(3);
    this->m_rocketShape.setRadius(10.f);
    this->m_rocketShape.setOrigin(10.f, 10.f);
    this->m_rocketShape.setFillColor(sf::Color::Red);
    this->m_rocketShape.setRotation(angleBetween(sf::Vector2f(0.f, -1.f), this->m_direction));
}

Missile::~Missile()
{

}

sf::Vector2f Missile::getTarget() const
{
    return this->m_target;
}


void Missile::setTarget(const sf::Vector2f& target)
{
    this->m_target = target;
}


bool Missile::update(const sf::Time& delta)
{
    if (distanceBetween(this->m_begin, this->getPosition()) >= distanceBetween(this->m_begin, this->m_target))
        return false;

    this->move(this->m_direction * this->m_speed * delta.asSeconds());

    this->m_rocketShape.setPosition(this->getPosition());
    this->m_trail.setEnd(this->getPosition());

    return true;
}

void Missile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->m_trail, states);
    target.draw(this->m_rocketShape, states);
}





