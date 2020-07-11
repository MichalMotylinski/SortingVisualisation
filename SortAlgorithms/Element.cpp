#include "Element.h"

Element::Element(float pWidth, float pHeight, int pNum)
{
	m_rect = sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
	m_rect.setOrigin(m_rect.getSize().x / 2, m_rect.getSize().y / 2);

	m_num = pNum;

	m_text.setCharacterSize(20);
	
	m_text.setString(std::to_string(m_num));
	m_text.setFillColor(sf::Color(0, 0, 0));
}

Element::~Element()
{
}

void Element::SetPosition(int pWidth, int pHeight)
{
	m_rect.setPosition((rand() % (pWidth - 220)) + 210, (rand() % (pHeight - 20)) + 10);
	if (m_num < 10)
	{
		m_text.setPosition(sf::Vector2f(m_rect.getPosition().x - m_rect.getSize().x / 4 + 1, m_rect.getPosition().y - m_rect.getSize().y / 2 - 2));
	}
	else
	{
		m_text.setPosition(sf::Vector2f(m_rect.getPosition().x - m_rect.getSize().x / 2 + 1, m_rect.getPosition().y - m_rect.getSize().y / 2 - 2));
	}
}

void Element::SetFont(sf::Font & pFont)
{
	m_text.setFont(pFont);
}
