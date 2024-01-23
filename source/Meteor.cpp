
#include "Meteor.hpp"
#include "VectorMath.hpp"

// meteor also inherits from projectile. Sets its own speed, and its own texture, like the missile.
// thinking this is a 'circle' meteor, vit. 
// no trail. But it travels down in a random direction, towards the floor. 

Meteor::Meteor(const sf::Vector2f& begin, const sf::Vector2f& target, float speed)
    : Projectile(begin, target, speed),
    m_direction(normalize(m_target - m_begin))
{
    // the meteor is a circle, bigger than the missile, but slower. 
    this->m_meteorShape.setRadius(25.f);
    this->m_meteorShape.setOrigin(25.f, 25.f);
    this->m_meteorShape.setFillColor(sf::Color::White);
    this->m_meteorShape.setRotation(angleBetween(sf::Vector2f(0.f, -1.f), this->m_direction));

}

Meteor::~Meteor()
{

}

sf::Vector2f Meteor::getTarget() const
{
    return this->m_target;
}

//returns the shape of the meteor - this is used for the collision detection. (:
sf::CircleShape Meteor::getShape() const
{
	return this->m_meteorShape;
}

bool Meteor::update(const sf::Time& delta)
{
    if (distanceBetween(this->m_begin, this->getPosition()) >= distanceBetween(this->m_begin, this->m_target))
        return false;

    this->move(this->m_direction * this->m_speed * delta.asSeconds());

    this->m_meteorShape.setPosition(this->getPosition());

    return true;
}

void Meteor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->m_meteorShape, states);
}



