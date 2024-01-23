#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include "SceneObject.hpp"

class Explosion : public SceneObject
{
    float m_radius;
    float m_targetRadius;
    sf::CircleShape m_borderShape;
public:
    Explosion(const sf::Vector2f& position, float radius);
    ~Explosion() override;

    bool update(const sf::Time& delta) override;
    sf::CircleShape getCircle();
    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
	
};

#endif