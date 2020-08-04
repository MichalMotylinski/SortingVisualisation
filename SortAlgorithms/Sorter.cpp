#include "Sorter.h"

Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}

sf::Time Sorter::BubbleSort(std::vector<Element*> &pElements)
{	
	m_clock.restart();

	int tLength = pElements.size();
	bool tSwapped = true;

	while (tSwapped)
	{
		tSwapped = false;
		for (int i = 1; i < tLength; ++i)
		{
			if (pElements[i - 1]->GetNumber() > pElements[i]->GetNumber())
			{
				Element* tTemp = pElements[i - 1];
				pElements[i - 1] = pElements[i];
				pElements[i] = (tTemp);
				tSwapped = true;
			}
		}
	}
	m_time = m_clock.getElapsedTime();
	return m_time;
}

sf::Time Sorter::MergeSort(std::vector<Element*>& pElements)
{
	m_clock.restart();
	MergeMain(pElements, 0, (int)pElements.size() - 1);

	m_time = m_clock.getElapsedTime();
	return m_time;
}

void Sorter::MergeMain(std::vector<Element*> &pElements, int pStart, int pEnd)
{
	if (pStart < pEnd)
	{
		int tMiddle = (pStart + pEnd) / 2;
		MergeMain(pElements, pStart, tMiddle);
		MergeMain(pElements, tMiddle + 1, pEnd);
		Merge(pElements, pStart, pEnd, tMiddle);
	}
}

void Sorter::Merge(std::vector<Element*> &pElements, int pStart, int pEnd, int pMiddle)
{
	std::vector<Element*> tLeftVector(pMiddle - pStart + 1);
	std::vector<Element*> tRightVector(pEnd - pMiddle);
	int tLeftIndex = 0;
	int tRightIndex = 0;
	int tCurrentIndex = pStart;

	for (size_t i = 0; i < tLeftVector.size(); ++i)
	{
		tLeftVector[i] = pElements[pStart + i];
	}

	for (size_t i = 0; i < tRightVector.size(); ++i)
	{
		tRightVector[i] = pElements[pMiddle + 1 + i];
	}

	while (tLeftIndex < tLeftVector.size() && tRightIndex < tRightVector.size())
	{
		if (tLeftVector[tLeftIndex]->GetNumber() <= tRightVector[tRightIndex]->GetNumber())
		{
			pElements[tCurrentIndex] = tLeftVector[tLeftIndex];
			tLeftIndex++;
		}
		else
		{
			pElements[tCurrentIndex] = tRightVector[tRightIndex];
			tRightIndex++;
		}
		tCurrentIndex++;
	}

	while (tLeftIndex < tLeftVector.size()) pElements[tCurrentIndex++] = tLeftVector[tLeftIndex++];

	while (tRightIndex < tRightVector.size()) pElements[tCurrentIndex++] = tRightVector[tRightIndex++];
}
