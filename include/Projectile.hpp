#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "SceneObject.hpp"

class Projectile : public SceneObject
{
protected: 
    sf::Vector2f m_begin;
    sf::Vector2f m_target;
    float m_speed;

public:
	Projectile(const sf::Vector2f& begin, const sf::Vector2f& target, float speed);
	virtual ~Projectile() override;
    
    virtual bool update(const sf::Time& delta);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const = 0;
};

#endif
