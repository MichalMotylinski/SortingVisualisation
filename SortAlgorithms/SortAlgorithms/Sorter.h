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

	sf::Time BubbleSort(std::vector<Element*> &pElements);
	std::vector<Element*> MergeSort(std::vector<Element*> &pElements);
	void MergeMain(std::vector<Element*> &pElements, int pLeftIndex, int pRightIndex);
	void Merge(std::vector<Element*>& pElements, int pLeftIndex, int pRightIndex, int pDivisionPoint);

private:
	sf::Clock m_clock;
	sf::Time m_time;
};
