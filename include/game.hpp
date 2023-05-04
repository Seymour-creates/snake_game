#ifndef SNAKE_GAME_GAME_HPP
#define SNAKE_GAME_GAME_HPP
#include <SFML/Graphics.hpp>
#include <memory>
#include "assetMan.hpp"
#include "StateMan.hpp"

enum AssetID
{
    MAIN_FONT = 0, TITLE_SCREEN_TEXT
};

struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;

    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game {
private:
    std::shared_ptr<Context> m_context;
    const sf::Time FRAME_RATE = sf::seconds(1.f/60);
public:
    Game();
    ~Game();

    void Run();
};


#endif //SNAKE_GAME_GAME_HPP
