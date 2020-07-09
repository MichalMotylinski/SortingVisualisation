#include "App.h"


App::App(int pWidth, int pHeight)
	: m_window(sf::VideoMode(pWidth, pHeight), "Sorting")
	, m_updateTime(sf::seconds(1.0f / 30.0f))
{
	m_font.loadFromFile("../Fonts/segoe-marker.ttf");
	srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		Element* tElement = new Element(20.0f, 20.0f, i);
		bool intersects = true;

		tElement->setPosition(pWidth, pHeight, i);

		while (intersects && m_elements.size() > 1)
		{
			int count = 0;
			for (int j = 0; j < int(m_elements.size()); j++)
			{
				if (tElement->GetRect().getGlobalBounds().intersects(m_elements[j]->GetRect().getGlobalBounds()))
				{
					tElement->setPosition(pWidth, pHeight, i);
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

App::~App()
{
}

void App::Update()
{
}

void App::Render()
{
	m_window.clear();
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

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				m_window.close();
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
