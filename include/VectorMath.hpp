#ifndef VECTOR_MATH_HPP
#define VECTOR_MATH_HPP

#include <SFML/Graphics.hpp>

float dot(const sf::Vector2f& vectorA, const sf::Vector2f& vectorB);
float length(const sf::Vector2f& vector);
float distanceBetween(const sf::Vector2f& pointA, const sf::Vector2f& pointB);
sf::Vector2f normalize(const sf::Vector2f& vector);
float angleBetween(const sf::Vector2f& directionA, const sf::Vector2f directionB);

#endif