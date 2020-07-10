#include "Button.h"
Button::Button(float pX,
	float pY,
	float pWidth,
	float pHeight,
	sf::Font* pFont,
	std::string pText,
	sf::Color pIdleColor,
	sf::Color pHoveredColor,
	sf::Color pPressedColor)
{
	this->m_buttonState = IDLE;

	this->m_shape.setPosition(sf::Vector2f(pX, pY));
	this->m_shape.setSize(sf::Vector2f(pWidth, pHeight));

	this->m_font = pFont;
	this->m_text.setFont(*this->m_font);
	this->m_text.setString(pText);
	this->m_text.setFillColor(sf::Color::White);
	this->m_text.setCharacterSize(12);
	this->m_text.setPosition(
		this->m_shape.getPosition().x / 2.f - this->m_text.getGlobalBounds().width / 2.f,
		this->m_shape.getPosition().y / 2.f - this->m_text.getGlobalBounds().height / 2.f
		);

	this->m_idleColor = pIdleColor;
	this->m_hoveredColor = pHoveredColor;
	this->m_pressedColor = pPressedColor;
}

Button::~Button()
{

}

void Button::Update(sf::Vector2f pMousePos)
{
	this->m_buttonState = IDLE;

	if (this->m_shape.getGlobalBounds.contains(pMousePos))
	{
		this->m_buttonState = HOVERED;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->m_buttonState = PRESSED;
		}
	}

	switch (this->m_buttonState)
	{
	case IDLE:
		this->m_shape.setFillColor(this->m_idleColor);
		break;
	case HOVERED:
		this->m_shape.setFillColor(this->m_hoveredColor);
		break;
	case PRESSED:
		this->m_shape.setFillColor(this->m_pressedColor);
		break;
	default:
		break;
	}
}

void Button::Render(sf::RenderTarget * pTarget)
{
	pTarget->draw(this->m_shape);
}
