#ifndef SNAKE_GAME_MAINMENU_HPP
#define SNAKE_GAME_MAINMENU_HPP
#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "game.hpp"

class MainMenu : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;

    bool m_isPlaySelected;
    bool m_isPlayPressed;
    bool m_isExitSelected;
    bool m_isExitPressed;

public:
    MainMenu(std::shared_ptr<Context>& context);

    ~MainMenu() override;

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};


#endif //SNAKE_GAME_MAINMENU_HPP
