#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Element.h"
#include "Button.h"
#include "Sorter.h"

class App
{
public:
	App(int pWidth, int pHeight);
	~App();

	void SpreadElements();
	Button* CreateButton(
		sf::Vector2f pPosition,
		sf::Vector2f pSize,
		int pAction,
		std::string pText,
		sf::Font& pFont,
		int pTextSize,
		sf::Color pFillColor,
		sf::Color pTextColor);

	void InitButtons();
	void HandleMouseButtons(sf::Mouse::Button pButton);
	void MoveElements(std::vector<Element*>& pElements);
	void SaveToFile();
	void LoadFromFile(int pNum);

	void Update();
	void Render();
	void Run();

private:
	sf::RenderWindow m_window;
	sf::Time  m_updateTime;
	sf::Clock m_sortClock;
	sf::Time m_sortTime;

	sf::Font m_font;
	sf::RectangleShape m_menu;
	std::vector<Element*> m_elements;
	std::vector<Button*> m_buttons;
	Sorter m_sorter;
	Button* m_sortTimer;

	enum
	{
		NONE,
		RESET,
		DEFAULT1,
		DEFAULT2,
		DEFAULT3,
		BUBBLE,
		MERGE,
		INSERT,
		QUICK,
		HEAP,
		COUNT
	};
};
