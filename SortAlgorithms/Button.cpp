#include "Button.h"
Button::Button(
	sf::Vector2f pSize,
	std::string pText,
	int pTextSize,
	sf::Color pFillColor,
	sf::Color pTextColor)
{
	m_shape.setSize(pSize);
	m_shape.setFillColor(pFillColor);

	m_text.setString(pText);
	m_text.setFillColor(pTextColor);

}

Button::~Button()
{

}

void Button::SetFillColor(sf::Color pColor)
{
	m_shape.setFillColor(pColor);
}

void Button::SetPosition(sf::Vector2f pPosition)
{
	m_shape.setPosition(pPosition);

	float tX = (pPosition.x + m_shape.getGlobalBounds().width) / 2 - (m_text.getGlobalBounds().width / 2);
	float tY = (pPosition.y + m_shape.getGlobalBounds().height) / 2 - (m_text.getGlobalBounds().height / 2);

	m_text.setPosition({ tX - 25, tY - 15 });
}

void Button::SetFont(sf::Font& pFont)
{
	m_text.setFont(pFont);
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


