#ifndef SCENE_HPP
#define SCENE_HPP

#include "SceneObject.hpp"

class Scene
{
    std::vector<SceneObject*> m_sceneObjects;
public:
    Scene();
    ~Scene();

	void addSceneObject(SceneObject* Sceneobject);
	void removeSceneObject(SceneObject* Sceneobject);
    std::vector<SceneObject*> getSceneObjects();
    void update(const sf::Time& delta);
	void draw(sf::RenderWindow& window);
};

#endif
