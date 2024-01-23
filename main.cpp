#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Projectile.hpp"
#include "SceneObject.hpp"
#include "Tower.hpp"
#include "Missile.hpp"
#include "Meteor.hpp"
#include "Explosion.hpp"
#include "Missile.hpp"
#include "Scene.hpp"
#include "VectorMath.hpp"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // A window is a target to render to
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Demo");

    sf::Clock clock;

	Scene* scene = new Scene();

    int userLifes = 3;
    sf::Text text;
    sf::Font font;
    
	if (!font.loadFromFile("arial.ttf"))
	{
		return 1;
	}
    text.setFont(font);
	text.setCharacterSize(24);

    bool running = true;
    int gameState = 1;
    while (running && window.isOpen())
    {
        // gamestate 1 = the meny, gamestate 2 = The actual game. 
        if (gameState == 1)
        {
			sf::Event event;

			window.clear();

			text.setCharacterSize(50);
			text.setString("Press 1 to start\nPress 2 to quit");
			text.setPosition(400 - text.getLocalBounds().width / 2, 300 - text.getLocalBounds().height / 2);
			window.draw(text);
			window.display();

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Num1)
                    { 
						// adds all the towers after the user presses 1. 
						delete scene;

                        
                        scene = new Scene();
						scene->addSceneObject(new Tower(sf::Vector2f(200, 550)));
						scene->addSceneObject(new Tower(sf::Vector2f(400, 550)));
						scene->addSceneObject(new Tower(sf::Vector2f(600, 550)));
						text.setCharacterSize(24);
						text.setPosition(10, 10);
						userLifes = 3;
						gameState = 2;
					}
                    // ends the game if user presses 2. 
					if (event.key.code == sf::Keyboard::Num2)
						running = false;
				}
			}
        }

        if (gameState == 2) 
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Q) 
                    {
						gameState = 1;
                    }
                }
                // Here we will check if user presses left click, if so then create a new missile from the tower
                else if (event.type == sf::Event::MouseButtonPressed)
                {
                    // I dont want the player to be able to shoot in the "death" screen, meteors keep falling. 
                    if (event.mouseButton.button == sf::Mouse::Left && userLifes > 0)
                    {
						// Since we know that the first three objects in the array are towers, we can use that knowledge to skip iterating through the loop
                        std::vector<SceneObject*> objects = scene->getSceneObjects();
                        std::vector<SceneObject*> towers(objects.begin(), objects.begin() + 3);

                        //Finds the closest tower ( not on cooldown (: )
                        SceneObject* closestTower = nullptr;
                        float closestDistance = 1000000;
                        for (SceneObject* tower : towers) 
                        {
                            //uses VectorMath to check distance between mouse and towers. 
                            float distance = distanceBetween(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), tower->getPosition());
                            if (distance < closestDistance && tower->canShoot()) 
                            {
                                closestDistance = distance;
                                closestTower = tower;
                            }
                        }
                        // shoots a missile from the closest tower. 
                        if (closestTower != nullptr)
                        {
                            scene->addSceneObject(new Missile(closestTower->getPosition(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y), 250.f));
                            closestTower->shoot();
                        }
                    }
                }
            }

            sf::Time delta = clock.restart();

            // meteors spawn by chance at the top and randomly goes to the ground, speed 70f.
            if (rand() % 10000 / delta.asSeconds() == 0) 
            {
                scene->addSceneObject(new Meteor(sf::Vector2f(rand() % 800, 0), sf::Vector2f(rand() % 800, 600), 70.f));
            }

            window.clear();
            // Everything in scene gets added to the vector, which updates the objects. 
			std::vector<SceneObject*> objects = scene->getSceneObjects();
            std::vector<SceneObject*> objectsToRemove;

            
            for (int i = 0; i < objects.size(); i++)
            {
                SceneObject* object = objects[i];
                window.draw(*object);
                bool result = object->update(delta);
                

                if (Missile* pmissile = dynamic_cast<Missile*>(object); pmissile)
                {
					// missile false = missile has hit. 
                    if (result == false)
                    {
						objectsToRemove.push_back(object);
                        scene->addSceneObject(new Explosion(object->getPosition(), 40.f));
                        continue;
                    }
                }
                
                if (Meteor* pmeteor = dynamic_cast<Meteor*>(object); pmeteor)
                {
                    // checks every meteor for the explosion. 
                    for (int j = 0; j < objects.size(); j++)
                    {

                        if (Explosion* pexplosion = dynamic_cast<Explosion*>(objects[j]); pexplosion)
                        {
                            //Gets the sum of the two circles (The meteor and the current explosion circle)
                            float radiusSum = pexplosion->getCircle().getRadius() + pmeteor->getShape().getRadius();
                            //Looks extremely messy but calculates the distance between the centers of the circles with pythagoreas theorem (a^2+b^2=c^2)
                            float distance = std::sqrt(std::pow(pexplosion->getCircle().getPosition().x - pmeteor->getShape().getPosition().x, 2) +
                                std::pow(pexplosion->getCircle().getPosition().y - pmeteor->getShape().getPosition().y, 2));

                            //Checks if the distance is less than the radius, if so the circles overlap and the meteor is shot
                            if (distance <= radiusSum)
                            {
								objectsToRemove.push_back(pmeteor);
								continue;
                            }
                        }
                    }

                    // checks if meteor has hit the ground;
                    if (result == false)
                    {
                        userLifes--;
						objectsToRemove.push_back(object);
						continue;
                    }
                }
                
                if (Explosion* pexplosion = dynamic_cast<Explosion*>(object); pexplosion)
                {
                    if (result == false)
                    {
						objectsToRemove.push_back(object);
						continue;
                    }
                }
            }
			objects.clear();
            for (int i = 0; i < objectsToRemove.size(); i++)
            {
                SceneObject* object = objectsToRemove[i];
                scene->removeSceneObject(object);
            }

            
            // overwrites the old text the game over text. 
            if (userLifes > 0)
            {
                text.setString(std::to_string(userLifes));
            }
            else
            {
                text.setCharacterSize(50);
                text.setString("Game Over!\nPress Q to return to the menu.");
                text.setPosition(400 - text.getLocalBounds().width / 2, 300 - text.getLocalBounds().height / 2);
            }
            
            window.draw(text);
            window.display();
        }
	}

	delete scene;
	_CrtDumpMemoryLeaks();

    return 0;
}
