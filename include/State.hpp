#ifndef SNAKE_GAME_STATE_HPP
#define SNAKE_GAME_STATE_HPP

#pragma once
#include <SFML/System.hpp>

namespace Engine
{
    class State
    {
    public:
        State(){};
        virtual ~State(){};

        virtual void Init() = 0;
        virtual void ProcessInput() = 0;
        virtual void Update(sf::Time deltaTime) = 0;
        virtual void Draw() = 0;

        virtual void Pause(){};
        virtual void Start() {};
    };
}
#endif //SNAKE_GAME_STATE_HPP
