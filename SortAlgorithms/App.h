#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Element.h"

class App
{
public:
	App(int pWidth, int pHeight);
	~App();

	void Update();
	void Render();
	void Run();

private:
	sf::RenderWindow m_window;

	sf::Time  m_updateTime;

	/*sf::RectangleShape m_element;
	sf::Text m_name;*/
	std::vector<Element*> m_elements;
	
	sf::Font m_font;
	
};

