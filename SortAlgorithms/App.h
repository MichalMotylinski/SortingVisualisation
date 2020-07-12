#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Element.h"
#include "Button.h"

class App
{
public:
	App(int pWidth, int pHeight);
	~App();

	void SpreadElements();
	Button* CreateButton(
		sf::Vector2f pPosition,
		sf::Vector2f pSize,
		std::string pText,
		sf::Font& pFont,
		int pTextSize,
		sf::Color pFillColor,
		sf::Color pTextColor);
	void InitButtons();

	void Update();
	void Render();
	void Run();

private:
	sf::RenderWindow m_window;
	sf::Time  m_updateTime;

	sf::Font m_font;

	sf::RectangleShape m_menu;
	std::vector<Element*> m_elements;
	std::vector<Button*> m_buttons;
	Button* m_button;
	enum
	{
		NONE,
		RESET,
		BUBBLE
	};
};

