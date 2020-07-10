#pragma once
#include <SFML/Graphics.hpp>

enum buttonStates{IDLE, HOVERED, PRESSED};

class Button
{
private:
	short unsigned m_buttonState;

	sf::RectangleShape m_shape;
	sf::Font* m_font;
	sf::Text m_text;

	sf::Color m_idleColor;
	sf::Color m_hoveredColor;
	sf::Color m_pressedColor;

public:
	Button(float pX,
		float pY,
		float pWidth,
		float pHeight,
		sf::Font* pFont,
		std::string pText,
		sf::Color pIdleColor,
		sf::Color pHoverColor,
		sf::Color pActiveColor);
	~Button();

	void Update(sf::Vector2f pMousePos);
	void Render(sf::RenderTarget* pTarget);
};

