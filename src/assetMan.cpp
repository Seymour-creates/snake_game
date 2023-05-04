#include <iostream>
#include "../include/assetMan.hpp"

namespace Engine {

    AssetMan::AssetMan()
    {

    }

    AssetMan::~AssetMan()
    {

    }

    void AssetMan::AddTexture(int id, const std::string &filePath, bool wantRepeated)
    {
        auto texture = std::make_unique<sf::Texture>();

        if ( texture->loadFromFile(filePath))
        {
            texture->setRepeated(wantRepeated);
            m_textures[id] = std::move(texture);
        }
    }

    void AssetMan::AddFont(int id, const std::string &filePath)
    {
        auto font = std::make_unique<sf::Font>();

        if (font->loadFromFile(filePath))
        {
            m_fonts[id] = std::move(font);
        }
    }

    const sf::Texture &AssetMan::GetTexture(int id) const
    {
        return *(m_textures.at(id).get());
    }

    const sf::Font &AssetMan::GetFont(int id) const
    {
        if (m_fonts.find(id) != m_fonts.end()) {
            return *(m_fonts.at(id).get());
        } else {
            std::cerr << "Font not found: " << id << std::endl;
            return *(m_fonts.at(id).get());
        }
    }
} // Engine