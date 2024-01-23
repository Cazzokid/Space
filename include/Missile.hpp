#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Projectile.hpp"
#include "Line.hpp"

class Missile : public Projectile
{
    sf::Vector2f m_direction;
    Line m_trail;
    // circle with 3 points is basically a triangle (: 
    sf::CircleShape m_rocketShape;

public:
    Missile(const sf::Vector2f& begin, const sf::Vector2f& target, float speed);
    ~Missile() override;

    sf::Vector2f getTarget() const;
    void setTarget(const sf::Vector2f& target);
    bool update(const sf::Time& delta) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};

#endif

