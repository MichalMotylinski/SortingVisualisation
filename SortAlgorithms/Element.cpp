#include "Element.h"

Element::Element(float pWidth, float pHeight, int pNum)
{
	m_rect = sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
	m_rect.setOrigin(m_rect.getSize().x / 2, m_rect.getSize().y / 2);

	m_font.loadFromFile("../Fonts/segoe-marker.ttf");

	m_text.setCharacterSize(20);
	m_text.setFont(m_font);
	m_text.setString(std::to_string(pNum));
	m_text.setFillColor(sf::Color(0, 0, 0));
}

Element::~Element()
{
}

void Element::setPosition(int pWidth, int pHeight, int pNum)
{
	m_rect.setPosition((rand() % (pWidth - 40)) + 20, (rand() % (pHeight - 40)) + 20);
	if (pNum < 10)
	{
		m_text.setPosition(sf::Vector2f(m_rect.getPosition().x - m_rect.getSize().x / 4 + 1, m_rect.getPosition().y - m_rect.getSize().y / 2 - 2));
	}
	else
	{
		m_text.setPosition(sf::Vector2f(m_rect.getPosition().x - m_rect.getSize().x / 2 + 1, m_rect.getPosition().y - m_rect.getSize().y / 2 - 2));
	}
}
