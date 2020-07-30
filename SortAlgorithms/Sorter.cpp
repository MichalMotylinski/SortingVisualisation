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
	std::cout << m_time.asSeconds();
	return m_time;
}

void Sorter::MergeSort(std::vector<Element*>& pElements)
{
}
