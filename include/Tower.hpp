#ifndef TOWER_HPP
#define TOWER_HPP

#include "SceneObject.hpp"

class Tower : public SceneObject
{
    sf::CircleShape m_sprite;
    sf::Time m_cooldown;
    sf::Time m_timeSinceLastShot;

public:
    Tower(const sf::Vector2f& position);
    ~Tower();

    bool update(const sf::Time& delta);
	bool canShoot();
    void shoot();
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};

#endif
