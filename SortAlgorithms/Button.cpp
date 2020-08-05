#include "Button.h"
Button::Button(
	sf::Vector2f pPosition,
	sf::Vector2f pSize,
	int pAction,
	std::string pText,
	sf::Font& pFont,
	int pTextSize,
	sf::Color pFillColor,
	sf::Color pTextColor)
{
	// Set values based on what was submitted
	m_action = pAction;
	m_shape.setPosition(pPosition);
	m_shape.setSize(pSize);
	m_defaultColor = (pFillColor);
	m_shape.setFillColor(m_defaultColor);

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

// Function to set default color of the button
void Button::SetDefaultColor()
{
	m_shape.setFillColor(m_defaultColor);
}

// Function to set color of the button when hovered
void Button::SetHoveredColor()
{
	if (m_action != 0)
	{
		auto tRed = m_defaultColor.r;
		auto tGreen = m_defaultColor.g;
		auto tBlue = m_defaultColor.b;
		if (tRed != 0)
		{
			if (tRed > 205)
			{
				tRed = 0;
			}
			tRed = tRed + 50;
		}
		if (tGreen != 0)
		{
			if (tGreen > 205)
			{
				tGreen = 0;
			}
			tGreen = tGreen + 50;
		}
		if (tBlue != 0)
		{
			if (tBlue > 205)
			{
				tBlue = 0;
			}
			tBlue = tBlue + 50;
		}
		m_shape.setFillColor(sf::Color(tRed, tGreen, tBlue));
	}
}

// Function to set color of the button when clicked
void Button::SetClickedColor()
{
	if (m_action != 0)
	{
		auto tRed = m_shape.getFillColor().r;
		auto tGreen = m_shape.getFillColor().g;
		auto tBlue = m_shape.getFillColor().b;
		if (tRed != 0)
		{
			if (tRed > 205)
			{
				tRed = 0;
			}
			tRed = tRed + 50;
		}
		if (tGreen != 0)
		{
			if (tGreen > 205)
			{
				tGreen = 0;
			}
			tGreen = tGreen + 50;
		}
		if (tBlue != 0)
		{
			if (tBlue > 205)
			{
				tBlue = 0;
			}
			tBlue = tBlue + 50;
		}
		m_shape.setFillColor(sf::Color(tRed, tGreen, tBlue));
	}
}

// Function to set color of the button text
void Button::SetTextColor(sf::Color pColor)
{
	m_text.setFillColor(pColor);
}

// Function to set the text of the button
void Button::SetText(std::string pText)
{
	m_text.setString(pText);
}

// Render button
void Button::DrawTo(sf::RenderWindow& pWindow)
{
	pWindow.draw(m_shape);
	pWindow.draw(m_text);
}

// Function checking if cursor is placed over the button
bool Button::MouseOver(sf::RenderWindow& pWindow)
{
	if (m_action != 0)
	{
		float tMouseX = (float)sf::Mouse::getPosition(pWindow).x;
		float tMouseY = (float)sf::Mouse::getPosition(pWindow).y;
		float tShapeStartX = m_shape.getPosition().x;
		float tShapeStartY = m_shape.getPosition().y;
		float tShapeEndX = m_shape.getPosition().x + m_shape.getGlobalBounds().width;
		float tShapeEndY = m_shape.getPosition().y + m_shape.getGlobalBounds().height;

		if (tShapeEndX > tMouseX && tMouseX > tShapeStartX && tShapeEndY > tMouseY && tMouseY > tShapeStartY)
		{
			return true;
		}
	}
	return false;
}
