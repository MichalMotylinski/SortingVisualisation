#include "Sorter.h"

Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}

// Function swapping elements of the vector

// Bubble sort function
sf::Time Sorter::BubbleSort(std::vector<Element*> &pElements)
{	
	// Restart clock
	m_clock.restart();

	// Set initial variables for vector length and swap checking
	int tLength = pElements.size();
	bool tSwapped = true;

	// Main bubble sort loop that breaks only when all elements were not swapped
	while (tSwapped)
	{
		tSwapped = false;
		// Loop through all elements in the list
		for (int i = 1; i < tLength; ++i)
		{
			// If currently checked number is smaller than previous number swap them
			if (pElements[i - 1]->GetNumber() > pElements[i]->GetNumber())
			{
				Element* tTemp = pElements[i - 1];
				pElements[i - 1] = pElements[i];
				pElements[i] = tTemp;
				tSwapped = true;
			}
		}
	}
	// Get time elapsed since start of the algorithm and return it
	m_time = m_clock.getElapsedTime();
	return m_time;
}

// Merge sort main function
sf::Time Sorter::MergeSort(std::vector<Element*>& pElements)
{
	// Restart clock
	m_clock.restart();
	// Begin merge sort algorithm by splitting the vector
	MergeSplit(pElements, 0, (int)pElements.size() - 1);
	// Get time elapsed since start of the algorithm and return it
	m_time = m_clock.getElapsedTime();
	return m_time;
}

// Merge sort splitting function
void Sorter::MergeSplit(std::vector<Element*> &pElements, int pStart, int pEnd)
{
	if (pStart < pEnd)
	{
		// Find centre point of the list
		int tMiddle = (pStart + pEnd) / 2;
		// Split left side of the list
		MergeSplit(pElements, pStart, tMiddle);
		// Split right side of the list
		MergeSplit(pElements, tMiddle + 1, pEnd);
		// Sort and merge elements
		Merge(pElements, pStart, pEnd, tMiddle);
	}
}

// Merge sort merging function
void Sorter::Merge(std::vector<Element*> &pElements, int pStart, int pEnd, int pMiddle)
{
	// Create temporary vectors for left and right part of the list
	std::vector<Element*> tLeftVector(pMiddle - pStart + 1);
	std::vector<Element*> tRightVector(pEnd - pMiddle);
	int tLeftIndex = 0;
	int tRightIndex = 0;
	int tCurrentIndex = pStart;

	// Populate the left part of the list
	for (int i = 0; i < (int)tLeftVector.size(); ++i)
	{
		tLeftVector[i] = pElements[pStart + i];
	}

	// Populate the right part of the list
	for (int i = 0; i < (int)tRightVector.size(); ++i)
	{
		tRightVector[i] = pElements[pMiddle + 1 + i];
	}

	// Main merging loop
	while (tLeftIndex < (int)tLeftVector.size() && tRightIndex < (int)tRightVector.size())
	{
		// Check which number in the sublist is smaller
		if (tLeftVector[tLeftIndex]->GetNumber() <= tRightVector[tRightIndex]->GetNumber())
		{
			// Update element in the current position
			pElements[tCurrentIndex] = tLeftVector[tLeftIndex];
			tLeftIndex++;
		}
		else
		{
			// Update element in the current position
			pElements[tCurrentIndex] = tRightVector[tRightIndex];
			tRightIndex++;
		}
		// Go to next position in the list
		tCurrentIndex++;
	}

	// Update all remaining elements if the left sublist is not empty
	while (tLeftIndex < (int)tLeftVector.size())
	{
		pElements[tCurrentIndex++] = tLeftVector[tLeftIndex++];
	}
	// Update all remaining elements if the right sublist is not empty
	while (tRightIndex < (int)tRightVector.size())
	{
		pElements[tCurrentIndex++] = tRightVector[tRightIndex++];
	}
}

sf::Time Sorter::InsertSort(std::vector<Element*>& pElements)
{
	m_clock.restart();
	int tSize = (int)pElements.size();

	for (int i = 1; i < tSize; i++)
	{
		int tCurrentElement = pElements[i]->GetNumber();
		int tPreviousIndex = i - 1;

		// Move element to the left until its number value is higher than value of the element before it
		while (tPreviousIndex >= 0 && pElements[tPreviousIndex]->GetNumber() > tCurrentElement)
		{
			pElements[tPreviousIndex + 1]->SetNumber(pElements[tPreviousIndex]->GetNumber());
			tPreviousIndex--;
		}
		pElements[tPreviousIndex + 1]->SetNumber(tCurrentElement);
	}

	m_time = m_clock.getElapsedTime();
	return m_time;
}

sf::Time Sorter::QuickSort(std::vector<Element*>& pElements)
{
	// Restart clock
	m_clock.restart();
	// Begin quick sort algorithm
	QuickMain(pElements, 0, (int)pElements.size() - 1);
	// Get time elapsed since start of the algorithm and return it
	m_time = m_clock.getElapsedTime();
	return m_time;
}

void Sorter::QuickMain(std::vector<Element*>& pElements, int pStart, int pEnd)
{
	if (pStart < pEnd)
	{
		int tSwapIndex = QuickSwap(pElements, pStart, pEnd);

		QuickMain(pElements, pStart, tSwapIndex - 1);
		QuickMain(pElements, tSwapIndex + 1, pEnd);
	}
}

int Sorter::QuickSwap(std::vector<Element*>& pElements, int pStart, int pEnd)
{
	Element* tElement = pElements[pEnd];
	int tLower = (pStart - 1);

	// Loop through all elements in the given sub-group
	for (int j = pStart; j <= pEnd - 1; j++)
	{
		if (pElements[j]->GetNumber() < tElement->GetNumber())
		{
			// Swap elements if current element from the loop is lower than element that we check for
			tLower++;
			Element* tTemp = pElements[tLower];
			pElements[tLower] = pElements[j];
			pElements[j] = tTemp;
		}
	}
	Element* tTemp = pElements[tLower + 1];
	pElements[tLower + 1] = pElements[pEnd];
	pElements[pEnd] = (tTemp);
	return (tLower + 1);
}

sf::Time Sorter::HeapSort(std::vector<Element*>& pElements)
{
	m_clock.restart();

	m_time = m_clock.getElapsedTime();
	return m_time;
}

sf::Time Sorter::CountSort(std::vector<Element*>& pElements)
{
	m_clock.restart();

	m_time = m_clock.getElapsedTime();
	return m_time;
}
