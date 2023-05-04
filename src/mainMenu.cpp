#include "../include/mainMenu.hpp"
#include <SFML/Window/Event.hpp>
MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context), m_isPlayPressed(false), m_isPlaySelected(true),
                                                        m_isExitPressed(false), m_isExitSelected(false)
{

}

MainMenu::~MainMenu(){}

void MainMenu::Init()
{
    // Title
    m_context->m_assets->AddFont(MAIN_FONT, "../assets/fonts/ChakraPetch-Regular.ttf");
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setString("Ziya's Snake Game");
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 150.f);

    // Play
    m_context->m_assets->AddFont(TITLE_SCREEN_TEXT, "../assets/fonts/DarumadropOne-Regular.ttf");
    m_playButton.setFont(m_context->m_assets->GetFont(TITLE_SCREEN_TEXT));
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_gameTitle.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2 + 25.f, m_context->m_window->getSize().y / 2 - 25.f);
    m_playButton.setCharacterSize(90);

    // Exit
    m_exitButton.setFont(m_context->m_assets->GetFont(TITLE_SCREEN_TEXT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_gameTitle.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2 );
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2 + 25.f, m_context->m_window->getSize().y / 2 + 100.f);
    m_exitButton.setCharacterSize(90);

}

void MainMenu::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) m_context->m_window->close();
        else
        {
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    if (!m_isPlaySelected)
                    {
                        m_isPlaySelected = true;
                        m_isExitSelected = false;
                    }
                    break;
                case sf::Keyboard::Down:
                    if (!m_isExitSelected)
                    {
                        m_isPlaySelected = false;
                        m_isExitSelected = true;
                    }
                    break;
                case sf::Keyboard::Enter:
                    m_isExitPressed = false;
                    m_isPlayPressed = false;

                    if (m_isPlaySelected) m_isPlayPressed = true;
                    else m_isExitPressed = true;
                    break;

            }
        }
    }
}

void MainMenu::Update(sf::Time deltaTime)
{
    if (m_isPlaySelected) {
        m_playButton.setFillColor(sf::Color::Blue);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else {
        m_exitButton.setFillColor(sf::Color::Blue);
        m_playButton.setFillColor(sf::Color::White);
    }

    if (m_isPlayPressed)
    {
        // ToDo:
        // Go to play state
    }
    else if (m_isExitPressed)
    {
        m_context->m_window->close();
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}


