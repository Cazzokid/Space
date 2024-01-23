#ifndef METEOR_HPP
#define METEOR_HPP

#include "Projectile.hpp"

class Meteor : public Projectile
{
    sf::Vector2f m_direction;
    sf::CircleShape m_meteorShape;

public:
    Meteor(const sf::Vector2f& begin, const sf::Vector2f& target, float speed);
    ~Meteor() override;

    sf::Vector2f getTarget() const;
	sf::CircleShape getShape() const;
    bool update(const sf::Time& delta) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};

#endif 