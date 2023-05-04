#include "../include/game.hpp"
#include "../include/mainMenu.hpp"
Game::Game() : m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(1400, 1400), "Ziya's Snake Game", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{

}

void Game::Run()
{
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Magenta);


    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;
    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();
        while (timeSinceLastFrame > FRAME_RATE)
        {
            timeSinceLastFrame -= FRAME_RATE;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(FRAME_RATE);
            m_context->m_states->GetCurrent()->Draw();
        }


    }
}