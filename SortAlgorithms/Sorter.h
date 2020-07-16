#pragma once
#include <string>
#include <iostream>
#include <chrono>

#include "Element.h"

class Sorter
{
public:
	Sorter();
	~Sorter();

	void BubbleSort(std::vector<Element*> &pElements);

private:
	sf::Clock m_clock;
	sf::Time m_time;
};
