// every class in the game inherits from SceneObject, 
// which has the update and draw functions.
// they will overshadow these functions in the derived classes.

#include "SceneObject.hpp"

SceneObject::SceneObject(const sf::Vector2f& position)
{
    this->setPosition(position);
}

SceneObject::~SceneObject()
{

}

bool SceneObject::update(const sf::Time& delta)
{
    return true;
}

void SceneObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

bool SceneObject::canShoot()
{
    return false;
}

void SceneObject::shoot(){

}

void SceneObject::setTarget(const sf::Vector2f& target){

}
sf::Vector2f SceneObject::getTarget()
{
    return sf::Vector2f(0.f, 0.f);
}
