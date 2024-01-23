#include "Line.hpp"

Line::Line(const sf::Vector2f& begin, const sf::Vector2f& end, const sf::Color& color) :
    m_begin(begin), m_end(end), m_color(color)
{

}

void Line::setBegin(const sf::Vector2f& begin)
{
    m_begin = begin;
}

void Line::setEnd(const sf::Vector2f& end)
{
    m_end = end;
}

void Line::setColor(const sf::Color& color)
{
    m_color = color;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Vertex vertices[] = {
        sf::Vertex(m_begin, m_color),
        sf::Vertex(m_end, m_color)
    };
    target.draw(vertices, 2, sf::Lines, states);
}
