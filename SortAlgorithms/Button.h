#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum buttonStates{IDLE, HOVERED, PRESSED};

class Button
{
public:
	Button(
		sf::Vector2f pPosition,
		sf::Vector2f pSize,
		std::string pText,
		sf::Font& pFont,
		int pTextSize,
		sf::Color pFillColor,
		sf::Color pTextColor);
	~Button();

	void SetFillColor(sf::Color pColor);
	void SetTextColor(sf::Color pColor);
	void DrawTo(sf::RenderWindow& pWindow);
	bool MouseOver(sf::RenderWindow& pWindow);

private:
	sf::RectangleShape m_shape;
	sf::Text m_text;
};

