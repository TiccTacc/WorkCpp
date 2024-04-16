#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <map>
#include <memory>

using namespace sf;

class GetTextures {
private:

	std::map <std::string, Texture> NameTextures;
	std::map <std::string, Font> NameFonts;
	std::map <std::string, std::unique_ptr <Shader >> NameShaders;
	
	static GetTextures* sInstance;

public:
	GetTextures();
	
	static Texture& GetTexture(std::string const& filename);
	static Font& GetFont(std::string const& filename);
	static Shader* GetShader(std::string const& vsFile, std::string const& fsFile);
};

GetTextures* GetTextures::sInstance = nullptr;

GetTextures::GetTextures() {
	assert(sInstance == nullptr); //Установка блокировки на дублирование 
	sInstance = this;
}

Texture& GetTextures::GetTexture(std::string const& filename) {
	
	auto& texMap	= sInstance->NameTextures;
	auto pairFound	= texMap.find(filename);

	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}

}

Font& GetTextures::GetFont(std::string const& filename) {
	
	auto& fontMap	= sInstance->NameFonts;
	auto pairFound	= fontMap.find(filename);

	if (pairFound != fontMap.end()){
		return pairFound->second;
	}
	else {
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

Shader* GetTextures::GetShader(std::string const& vsFile, std::string const& fsFile) {
	
	auto& shaderMap = sInstance->NameShaders;
	auto combinedKey = vsFile + ";" + fsFile;
	auto pairFound = shaderMap.find(combinedKey);

	if (pairFound != shaderMap.end()) {
		return pairFound->second.get();
	}
	else {
		auto& shader = (shaderMap[combinedKey] = std::unique_ptr<Shader>(new Shader()));
		shader->loadFromFile(vsFile, fsFile);
		return shader.get();
	}

}