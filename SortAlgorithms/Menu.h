#pragma once
#include "Button.h"

class Menu
{
public:
	Menu(sf::Vector2f pPosition, sf::Vector2f pSize);
	~Menu();

	void AddButton();
	void Render(sf::RenderWindow pWindow);
private:

};

