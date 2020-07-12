#include "Button.h"
Button::Button(
	sf::Vector2f pPosition,
	sf::Vector2f pSize,
	std::string pText,
	sf::Font& pFont,
	int pTextSize,
	sf::Color pFillColor,
	sf::Color pTextColor)
{
	m_shape.setPosition(pPosition);
	m_shape.setSize(pSize);
	m_shape.setFillColor(pFillColor);

	m_text.setString(pText);
	m_text.setFillColor(pTextColor);
	m_text.setFont(pFont);

	m_text.setOrigin(m_text.getLocalBounds().left + m_text.getLocalBounds().width / 2.0f, m_text.getLocalBounds().top + m_text.getLocalBounds().height / 2.0f);

	float tX = (m_shape.getPosition().x + m_shape.getSize().x / 2.0f);
	float tY = (m_shape.getPosition().y + m_shape.getSize().y / 2.0f);
	
	m_text.setPosition({ tX, tY });
}

Button::~Button()
{

}

void Button::SetFillColor(sf::Color pColor)
{
	m_shape.setFillColor(pColor);
}

void Button::SetTextColor(sf::Color pColor)
{
	m_text.setFillColor(pColor);
}

void Button::DrawTo(sf::RenderWindow& pWindow)
{
	pWindow.draw(m_shape);
	pWindow.draw(m_text);
}

bool Button::MouseOver(sf::RenderWindow& pWindow)
{
	float tMouseX = sf::Mouse::getPosition(pWindow).x;
	float tMouseY = sf::Mouse::getPosition(pWindow).y;

	float tShapeStartX = m_shape.getPosition().x;
	float tShapeStartY = m_shape.getPosition().y;
	float tShapeEndX = m_shape.getPosition().x + m_shape.getGlobalBounds().width;
	float tShapeEndY = m_shape.getPosition().y + m_shape.getGlobalBounds().height;
	
	if (tShapeEndX > tMouseX && tMouseX > tShapeStartX && tShapeEndY > tMouseY && tMouseY > tShapeStartY)
	{
		return true;
	}
	return false;
}


