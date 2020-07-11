#include "App.h"


App::App(int pWidth, int pHeight)
	: m_window(sf::VideoMode(pWidth, pHeight), "Sorting")
	, m_updateTime(sf::seconds(1.0f / 30.0f))
	, m_menu(sf::Vector2f(200, 800))
{
	m_menu.setFillColor(sf::Color(0, 130, 0));
	
	m_font.loadFromFile("../Fonts/segoe-marker.ttf");
	m_button = new Button({ 150, 75 }, "Reset", 20, sf::Color(150, 150, 0), sf::Color::White);
	m_button->SetPosition({ 10, 10 });
	m_button->SetFont(m_font);

	srand(time(0));
	SpreadElements();
}

App::~App()
{
	delete this->m_button;
}

void App::SpreadElements()
{	
	
	m_elements.clear();

	for (int i = 0; i < 100; i++)
	{
		Element* tElement = new Element(20.0f, 20.0f, i);
		bool intersects = true;

		tElement->SetFont(m_font);
		tElement->SetPosition(m_window.getSize().x, m_window.getSize().y);

		while (intersects && m_elements.size() > 1)
		{
			int count = 0;
			for (int j = 0; j < int(m_elements.size()); j++)
			{
				if (tElement->GetRect().getGlobalBounds().intersects(m_elements[j]->GetRect().getGlobalBounds()))
				{
					tElement->SetPosition(m_window.getSize().x, m_window.getSize().y);
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

void App::Update()
{
	//this->m_button->Update(this->mousePosView);
}

void App::Render()
{
	m_window.clear();
	m_window.draw(m_menu);
	m_button->DrawTo(m_window);
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
				if (m_button->MouseOver(m_window) && tPressed == false)
				{
					m_button->SetFillColor(sf::Color(200, 200, 0));
					break;
				}
				else if (m_button->MouseOver(m_window) && tPressed == true)
				{
					m_button->SetFillColor(sf::Color(255, 255, 0));
					break;
				}
				else
				{
					m_button->SetFillColor(sf::Color(150, 150, 0));
					break;
				}
			case sf::Event::MouseButtonPressed:
				if (m_button->MouseOver(m_window) && tPressed == false)
				{
					SpreadElements();
					m_button->SetFillColor(sf::Color(255, 255, 0));
					tPressed = true;
					break;
				}
			case sf::Event::MouseButtonReleased:
				if (m_button->MouseOver(m_window))
				{
					m_button->SetFillColor(sf::Color(200, 200, 0));
					tPressed = false;
					break;
				}
				else
				{
					m_button->SetFillColor(sf::Color(150, 150, 0));
					tPressed = false;
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


