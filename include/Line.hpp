#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>

class Line : public sf::Drawable
{
    sf::Vector2f m_begin;
    sf::Vector2f m_end;
    sf::Color m_color;

public:

    Line(const sf::Vector2f& begin, const sf::Vector2f& end, const sf::Color& color = sf::Color::White);

    void setBegin(const sf::Vector2f& begin);
    void setEnd(const sf::Vector2f& end);
    void setColor(const sf::Color& color);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
};

#endif