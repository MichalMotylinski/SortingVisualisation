#include "App.h"


App::App(int pWidth, int pHeight)
	: m_window(sf::VideoMode(pWidth, pHeight), "Sorting")
	, m_updateTime(sf::seconds(1.0f / 30.0f))
	, m_menu(sf::Vector2f(200, 800))
{
	m_menu.setFillColor(sf::Color(0, 100, 0));
	

	m_font.loadFromFile("../Fonts/segoe-marker.ttf");
	InitButtons();

	srand(int(time(0)));
	SpreadElements();
	//SaveToFile();
}

App::~App()
{
	for (auto tElement : m_elements)
	{
		if (tElement != nullptr)
		{
			delete tElement;
		}
	}
}

void App::SpreadElements()
{	
	
	m_elements.clear();
	int tListLenght = 100;

	for (int i = 0; i < tListLenght; i++)
	{
		Element* tElement = new Element(20.0f, 20.0f, tListLenght, m_font, m_window);
		bool intersects = true;

		while (intersects && m_elements.size() > 1)
		{
			int count = 0;
			for (int j = 0; j < int(m_elements.size()); j++)
			{
				if (tElement->GetRect().getGlobalBounds().intersects(m_elements[j]->GetRect().getGlobalBounds()))
				{
					tElement->SetRandPosition(m_window.getSize().x, m_window.getSize().y);
					intersects = true;
					break;
				}
				else
				{
					count = count + 1;
				}
				if (count == m_elements.size())
				{
					intersects = false;
				}
			}
		}
		m_elements.push_back(tElement);
	}
}

Button* App::CreateButton(
	sf::Vector2f pPosition,
	sf::Vector2f pSize,
	int pAction,
	std::string pText,
	sf::Font& pFont,
	int pTextSize,
	sf::Color pFillColor,
	sf::Color pTextColor)
{
	Button* tButton = new Button(pPosition, pSize, pAction, pText, pFont, pTextSize, pFillColor, pTextColor);

	return tButton;
}

void App::InitButtons()
{
	m_buttons.push_back(CreateButton({ 20, 10 }, { 160, 50 }, RESET, "Reset", m_font, 20, sf::Color(125, 125, 0), sf::Color::White));
	m_buttons.push_back(CreateButton({ 20, 80 }, { 160, 50 }, DEFAULT1, "Default 1", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));
	m_buttons.push_back(CreateButton({ 20, 150 }, { 160, 50 }, DEFAULT2, "Default 2", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));
	m_buttons.push_back(CreateButton({ 20, 220 }, { 160, 50 }, DEFAULT3, "Default 3", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));
	m_buttons.push_back(CreateButton({ 20, 290 }, { 160, 50 }, BUBBLE, "Bubble Sort", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));
	m_buttons.push_back(CreateButton({ 20, 360 }, { 160, 50 }, MERGE, "Merge Sort", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));

	m_buttons.push_back(CreateButton({ 0, 730 }, { 200, 50 }, NONE, std::to_string(m_sortTime.asSeconds()), m_font, 20, sf::Color(105, 105, 105), sf::Color::White));

}

void App::HandleMouseButtons(sf::Mouse::Button pButton)
{
	switch (pButton)
	{
	case sf::Mouse::Left:
	{
		for (int i = 0; i < int(m_buttons.size()); i++)
		{
			if (m_buttons[i]->MouseOver(m_window))
			{
				m_buttons[i]->SetClickedColor();
				m_buttons[i]->SetIsPressed(true);
				if (m_buttons[i]->GetAction() == RESET)
				{
					m_buttons.back()->SetText("0.000000");
					SpreadElements();
				}
				else if (m_buttons[i]->GetAction() == DEFAULT1)
				{
					LoadFromFile(1);
				}
				else if (m_buttons[i]->GetAction() == DEFAULT2)
				{
					LoadFromFile(2);
				}
				else if (m_buttons[i]->GetAction() == DEFAULT3)
				{
					LoadFromFile(3);
				}
				else if (m_buttons[i]->GetAction() == BUBBLE)
				{
					m_sortTime = m_sorter.BubbleSort(m_elements);
					MoveElements(m_elements);
					m_buttons.back()->SetText(std::to_string(m_sortTime.asSeconds()));
				}
				else if (m_buttons[i]->GetAction() == MERGE)
				{
					
					m_sortTime = m_sorter.MergeSort(m_elements);
					MoveElements(m_elements);
					m_buttons.back()->SetText(std::to_string(m_sortTime.asSeconds()));
				}
			}
		}
	}
	}
}

void App::MoveElements(std::vector<Element*>& pElements)
{
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

void App::SaveToFile()
{
	std::ofstream file;
	std::string tData;
	file.open("test2.txt");
	for (int i = 0; i < (int)m_elements.size(); i++)
	{
		if (i == 0)
		{
			tData = m_elements[i]->GetPosition();
		}
		else
		{
			tData = tData + "\n" + m_elements[i]->GetPosition();
		}
	}
	file << tData;
	file.close();
}

void App::LoadFromFile(int pNum)
{
	std::ifstream file("test" + std::to_string(pNum) + ".txt");
	int i = 0;
	for ( std::string line; std::getline(file, line); )
	{

		std::istringstream sstream(line);
		std::vector<std::string> tResults((std::istream_iterator<std::string>(sstream)), std::istream_iterator<std::string>());
		//std::cout << " " << i << " " << tResults[0] << "," << tResults[1];
		m_elements[i]->SetNumber(int(std::stof(tResults[2])));
		m_elements[i]->SetPosition(int(std::stof(tResults[0])), int(std::stof(tResults[1])));
		i++;
	}
}

void App::Update()
{
}

void App::Render()
{
	m_window.clear();
	m_window.draw(m_menu);
	for (int i = 0; i < int(m_buttons.size()); i++)
	{
		m_buttons[i]->DrawTo(m_window);
	}

	for (int i = 0; i < int(m_elements.size()); i++)
	{
		m_window.draw(m_elements[i]->GetRect());
		m_window.draw(m_elements[i]->GetText());
	}
	m_window.display();
}

void App::Run()
{
	sf::Clock clock;

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	bool tPressed = false;
	while (m_window.isOpen())
	{
		sf::Event tEvent;
		while (m_window.pollEvent(tEvent))
		{
			switch (tEvent.type)
			{
			case sf::Event::Closed:
				m_window.close();
			case sf::Event::MouseMoved:
			{
				for (int i = 0; i < int(m_buttons.size()); i++)
				{
					if (m_buttons[i]->GetIsPressed() == false)
					{
						if (m_buttons[i]->MouseOver(m_window))
						{
							m_buttons[i]->SetHoveredColor();
						}
						else
						{
							m_buttons[i]->SetDefaultColor();
						}
					}
				}
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				HandleMouseButtons(tEvent.mouseButton.button);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				for (int i = 0; i < int(m_buttons.size()); i++)
				{
					if (m_buttons[i]->MouseOver(m_window))
					{
						m_buttons[i]->SetHoveredColor();
						m_buttons[i]->SetIsPressed(false);
					}
					else
					{
						m_buttons[i]->SetDefaultColor();
						m_buttons[i]->SetIsPressed(false);
					}
				}
				break;
			}
			}	
		}

		sf::Time tDeltaTime = clock.restart();

		timeSinceLastUpdate += tDeltaTime;

		while (timeSinceLastUpdate > m_updateTime)
		{
			Update();

			timeSinceLastUpdate -= m_updateTime;
		}

		Render();
	}
}
