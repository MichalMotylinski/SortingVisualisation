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

	void Update();
	void Render();
	void Run();

private:
	sf::RenderWindow m_window;
	sf::Time  m_updateTime;

	sf::Font m_font;

	sf::RectangleShape m_menu;
	std::vector<Element*> m_elements;
	Button* m_button;
	enum
	{
		NONE,
		RESET
	};
};

