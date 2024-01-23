#include "Explosion.hpp"

Explosion::Explosion(const sf::Vector2f& position, float radius) :
    SceneObject(position), m_radius(0), m_targetRadius(radius)
{
    m_borderShape.setPosition(this->getPosition());
    m_borderShape.setRadius(m_radius);
    m_borderShape.setOrigin(m_radius, m_radius);
    m_borderShape.setFillColor(sf::Color::Transparent);
    m_borderShape.setOutlineColor(sf::Color::White);
    m_borderShape.setOutlineThickness(1.0f);
}

Explosion::~Explosion()
{

}

bool Explosion::update(const sf::Time& delta)
{
    if (m_radius >= m_targetRadius)
        return false;

    m_radius += 100.0f * delta.asSeconds();
    m_borderShape.setOrigin(m_radius, m_radius);

    m_borderShape.setRadius(m_radius);

    return true;
}

sf::CircleShape Explosion::getCircle()
{
	sf::CircleShape circle;
	circle.setPosition(this->getPosition());
	circle.setRadius(m_radius);
	circle.setOrigin(m_radius, m_radius);
	circle.setFillColor(sf::Color::Transparent);
	return circle;
}

void Explosion::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_borderShape, states);
}
