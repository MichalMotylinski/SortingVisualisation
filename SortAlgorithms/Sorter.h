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
	sf::Time MergeSort(std::vector<Element*> &pElements);
	void Split(std::vector<Element*> &pElements, int pLeftIndex, int pRightIndex);
	void Merge(std::vector<Element*> &pElements, int pLeftIndex, int pRightIndex, int pMiddle);
	sf::Time InsertSort(std::vector<Element*> &pElements);
	sf::Time QuickSort(std::vector<Element*> &pElements);
	sf::Time HeapSort(std::vector<Element*> &pElements);
	sf::Time CountSort(std::vector<Element*> &pElements);

private:
	sf::Clock m_clock;
	sf::Time m_time;
};
