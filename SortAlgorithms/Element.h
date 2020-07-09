#pragma once
#include <SFML/Graphics.hpp>

class Element
{
public:
	Element(float pWidth, float pHeight, int pNum);
	~Element();

	void setPosition(int pWidth, int pHeight, int pNum);

	inline sf::RectangleShape& GetRect() { return m_rect; }

	inline sf::Text& GetText() { return m_text; }

private:
	sf::RectangleShape m_rect;
	sf::Text m_text;

	sf::Font m_font;
	
};

