#ifndef SCENE_OBJECT_HPP
#define SCENE_OBJECT_HPP

#include <SFML/Graphics.hpp>

class SceneObject : public sf::Drawable, public sf::Transformable
{
public:
    SceneObject(const sf::Vector2f& position);
    virtual ~SceneObject();

    virtual bool update(const sf::Time& delta);
    virtual bool canShoot();
    virtual void shoot();
    virtual void setTarget(const sf::Vector2f& target);
    virtual sf::Vector2f getTarget();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const = 0;
};

#endif
