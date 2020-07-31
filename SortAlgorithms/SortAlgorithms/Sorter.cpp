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

std::vector<Element*> Sorter::MergeSort(std::vector<Element*>& pElements)
{
	m_clock.restart();

	std::vector<Element*> tLeftVector;
	std::vector<Element*> tRightVector;
	std::vector<Element*> tResultsVector;

	int tMiddle = ((int)pElements.size() + 1) / 2;
	for (int i = 0; i < tMiddle; i++)
	{
		tLeftVector.push_back(pElements[i]);
	}

	for (int i = tMiddle; i < (int)pElements.size(); i++)
	{
		tRightVector.push_back(pElements[i]);
	}

	tLeftVector = MergeSort(tLeftVector);
	tRightVector = MergeSort(tRightVector);
	tResultsVector = Merge(tLeftVector, tRightVector);

	m_time = m_clock.getElapsedTime();
	return tResultsVector;
}

void Sorter::MergeMain(std::vector<Element*>& pElements, int pLeftIndex, int pRightIndex)
{
	if (pLeftIndex < pRightIndex)
	{
		int tDivisionPoint = pLeftIndex + (pRightIndex - pLeftIndex) / 2;
		MergeMain(pElements, pLeftIndex, tDivisionPoint);
		MergeMain(pElements, tDivisionPoint + 1, pRightIndex);

		Merge(pElements, pLeftIndex, pRightIndex, tDivisionPoint);
	}
}

void Sorter::Merge(std::vector<Element*>& pElements, int pLeftIndex, int pRightIndex, int pDivisionPoint)
{
	int tSubArray1Size = pDivisionPoint - pLeftIndex + 1;
	int tSubArray2Size = pRightIndex - pDivisionPoint;

	int n1 = pDivisionPoint - pLeftIndex + 1;

	int tSubArray1[tSubArray1Size]; 
	int tSubArray2[tSubArray2Size];
}
