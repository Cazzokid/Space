#include "VectorMath.hpp"
#include <cmath>

float dot(const sf::Vector2f& vectorA, const sf::Vector2f& vectorB)
{
    return vectorA.x * vectorB.x + vectorA.y * vectorB.y;
}

float length(const sf::Vector2f& vector)
{
    return std::sqrt(dot(vector, vector));
}

float distanceBetween(const sf::Vector2f& pointA, const sf::Vector2f& pointB)
{
    return length(pointB - pointA);
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
    return vector / length(vector);
}

float angleBetween(const sf::Vector2f& directionA, const sf::Vector2f directionB)
{
    sf::Vector2f normalizedA = normalize(directionA);
    sf::Vector2f normalizedB = normalize(directionB);
    float angleRadians = std::atan2(normalizedB.y, normalizedB.x) - std::atan2(normalizedA.y, normalizedA.x);
    float angleDegrees = angleRadians * 180.f / 3.14159265359f;
    return angleDegrees;
}
