#pragma once
#include <string>
#include <iostream>

#include "Element.h"

class Sorter
{
public:
	Sorter();
	~Sorter();

	void BubbleSort(std::vector<Element*> &pElements);
};
