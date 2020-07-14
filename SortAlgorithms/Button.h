#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(
		sf::Vector2f pPosition,
		sf::Vector2f pSize,
		int pAction,
		std::string pText,
		sf::Font& pFont,
		int pTextSize,
		sf::Color pFillColor,
		sf::Color pTextColor);
	~Button();

	void SetDefaultColor();
	void SetHoveredColor();
	void SetClickedColor();
	void SetTextColor(sf::Color pColor);
	void DrawTo(sf::RenderWindow& pWindow);
	bool MouseOver(sf::RenderWindow& pWindow);

	inline bool GetIsPressed() { return m_isPressed;  }
	inline void SetIsPressed(bool pIsPressed) { m_isPressed = pIsPressed; }
	inline int GetAction() { return m_action; }

private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
	sf::Color m_defaultColor;
	bool m_isPressed = false;
	int m_action;
};

