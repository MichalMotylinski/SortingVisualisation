#include "Sorter.h"

Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}

void Sorter::BubbleSort(std::vector<Element*> &pElements)
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
	for (int i = 0; i < int(pElements.size()); i++)
	{
		if (i < 25)
		{
			pElements[i]->SetPosition((i * 25) + 400, 50);
		}
		else if (i < 50)
		{
			pElements[i]->SetPosition(((i - 25) * 25) + 400, 80);
		}
		else if (i < 75)
		{
			pElements[i]->SetPosition(((i - 50) * 25) + 400, 110);
		}
		else if (i < 100)
		{
			pElements[i]->SetPosition(((i - 75) * 25) + 400, 140);
		}
	}
}
