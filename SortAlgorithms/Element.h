#pragma once
#include <SFML/Graphics.hpp>

class Element
{
public:
	Element(float pWidth, float pHeight, int pNum, sf::Font& pFont, sf::RenderWindow& pWindow);
	~Element();

	void SetRandPosition(int pWidth, int pHeight);
	void SetPosition(int pWidth, int pHeight);
	void SetFont(sf::Font& pFont);

	inline sf::RectangleShape& GetRect() { return m_rect; }
	inline sf::Text& GetText() { return m_text; }

	void SetRandNumber();
	void SetNumber(int pNum);
	inline int GetNumber() { return m_num; }
	
private:
	sf::RectangleShape m_rect;
	sf::Text m_text;
	int m_num;
	sf::Font m_font;
};

