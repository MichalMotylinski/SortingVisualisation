#include "Element.h"

Element::Element(float pWidth, float pHeight, int pListLenght, sf::Font& pFont, sf::RenderWindow& pWindow)
{
	m_rect = sf::RectangleShape(sf::Vector2f(pWidth, pHeight));
	SetRandNumber();
	m_text.setCharacterSize(20);
	m_text.setString(std::to_string(m_num));
	m_text.setFillColor(sf::Color(0, 0, 0));
	m_text.setFont(pFont);
	m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);
	SetRandPosition(pWindow.getSize().x, pWindow.getSize().y);
}

Element::~Element()
{
}

void Element::SetRandPosition(int pWidth, int pHeight)
{
	m_rect.setPosition((rand() % (pWidth - 220)) + 200, (rand() % (pHeight - 20)));
	float tX = (m_rect.getPosition().x + m_rect.getSize().x / 2.0f);
	float tY = (m_rect.getPosition().y + m_rect.getSize().y / 2.0f);
	m_text.setPosition({ tX, tY });
}

void Element::SetPosition(int pWidth, int pHeight)
{
	m_rect.setPosition(pWidth, pHeight);
	float tX = (m_rect.getPosition().x + m_rect.getSize().x / 2.0f);
	float tY = (m_rect.getPosition().y + m_rect.getSize().y / 2.0f);
	m_text.setPosition({ tX, tY });
}

std::string Element::GetPosition()
{
	sf::Vector2f tRectPosition = m_rect.getPosition();
	sf::Vector2f tTextPosition = m_text.getPosition();
	std::string tData = std::to_string(tRectPosition.x) + " " + std::to_string(tRectPosition.y) + " " + std::to_string(m_num);// + ";" + std::to_string(tTextPosition.x) + "," + std::to_string(tTextPosition.y);
	return tData;
}

void Element::SetFont(sf::Font& pFont)
{
	m_text.setFont(pFont);
}

void Element::SetRandNumber()
{
	m_num = rand() % 100;
}

void Element::SetNumber(int pNum)
{
	m_num = pNum;
	m_text.setString(std::to_string(m_num));
	m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);
}
