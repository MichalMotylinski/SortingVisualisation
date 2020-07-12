#pragma once
#include <SFML/Graphics.hpp>

#include "Button.h"

class Panel
{
public:
	Panel(sf::Vector2f pPosition,  sf::Vector2f pSize);
	~Panel();

	/*void AddButton(
		sf::Vector2f pSize,
		std::string pText,
		int pTextSize,
		sf::Color pFillColor,
		sf::Color pTextColor);*/

	void UpdatePanel();
	void RenderPanel();

private:
	sf::RectangleShape m_panel;
	std::vector<Button*> m_buttonsVect;
};

