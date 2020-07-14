#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::SortBubble(std::vector<Element*> &pElements)
{
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
		
		for (int i = 0; i < int(pElements.size()); i++)
		{
			std::cout << pElements[i]->GetNumber() << " ";
			if (i < 50)
				pElements[i]->SetPosition(i * 25.0f, 20.0f);
			/*else
			{
				pElements[i]->SetPosition((i - 51) * 20.0f, 40.0f);
			}*/
		}
		std::cout << "\n";
	}
}
