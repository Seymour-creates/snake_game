#ifndef SNAKE_GAME_STATEMAN_HPP
#define SNAKE_GAME_STATEMAN_HPP

#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

namespace Engine
{
    class StateMan
    {
    private:
        std::stack<std::unique_ptr<State>> m_stateStack;
        std::unique_ptr<State> m_newState;

        bool m_add;
        bool m_remove;
        bool m_replace;
    public:
        StateMan();
        ~StateMan();

        void Add(std::unique_ptr<State> toAdd, bool replace = false);
        void PopCurrent();
        void ProcessStateChange();
        std::unique_ptr<State>& GetCurrent();
    };
}
#endif //SNAKE_GAME_STATEMAN_HPP
