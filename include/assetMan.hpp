//
// Created by Romelo Gilbert on 5/3/23.
//

#ifndef SNAKE_GAME_ASSETMAN_HPP
#define SNAKE_GAME_ASSETMAN_HPP

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

namespace Engine
{

    class AssetMan
    {
    private:
    std::map<int, std::unique_ptr<sf::Texture>> m_textures;
    std::map<int, std::unique_ptr<sf::Font>> m_fonts;

    public:
        AssetMan();
        ~AssetMan();

        void AddTexture(int id, const std::string& filePath, bool wantRepeated = false);
        void AddFont(int id, const std::string& filePath);

        [[nodiscard]] const sf::Texture& GetTexture(int id) const;
        [[nodiscard]] const sf::Font& GetFont(int id) const;
    };

} // Engine

#endif //SNAKE_GAME_ASSETMAN_HPP
