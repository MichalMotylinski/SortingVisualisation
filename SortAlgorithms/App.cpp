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
}

App::~App()
{
	delete this->m_button;
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
	m_buttons.push_back(CreateButton({ 20, 80 }, { 160, 50 }, BUBBLE, "Bubble Sort", m_font, 20, sf::Color(125, 0, 125), sf::Color::White));
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
					SpreadElements();
				else if (m_buttons[i]->GetAction() == BUBBLE)
					m_sorter.BubbleSort(m_elements);
			}
		}
	}
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
