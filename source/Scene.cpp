// collects every sceneobject and updates them by calling their update function.

#include "Scene.hpp"
#include "SceneObject.hpp"
#include <memory>

Scene::Scene()
{
    this->m_sceneObjects = std::vector<SceneObject*>();
}

Scene::~Scene()
{
	for (int i = 0; i < this->m_sceneObjects.size(); i++)
	{
		delete this->m_sceneObjects[i];
	}
	this->m_sceneObjects.clear();
}

void Scene::addSceneObject(SceneObject* sceneObject)
{
    this->m_sceneObjects.push_back(sceneObject);
}

void Scene::removeSceneObject (SceneObject* sceneObject)
{
	for (int i = 0; i < this->m_sceneObjects.size(); i++)
	{
		if (this->m_sceneObjects[i] == sceneObject)
		{
			delete this->m_sceneObjects[i];
			this->m_sceneObjects.erase(this->m_sceneObjects.begin() + i);
		}
	}
}


std::vector<SceneObject*> Scene::getSceneObjects()
{
	return this->m_sceneObjects;
}


void Scene::update(const sf::Time& delta)
{
    for (auto& sceneObject : this->m_sceneObjects)
    {
        sceneObject->update(delta);
    }
}


void Scene::draw(sf::RenderWindow& window)
{
	for (auto& sceneObject : this->m_sceneObjects)
	{
		sceneObject->draw(window);
	}
}
