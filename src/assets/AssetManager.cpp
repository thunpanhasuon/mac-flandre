#include "AssetManager.h"

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

void AssetManager::hello() {
  std::cout << "hello\n";
}

std::vector<Texture2D> AssetManager::LoadAsset(const std::string &path,
                                             const std::string &animation) {
  std::ifstream file(path);
  nlohmann::json assets;
  file >> assets;

  std::vector<Texture2D> textures;

  for (std::size_t i = 0; i < assets[animation].size(); i++) {
    std::string texturePath = assets[animation][i];
    Texture2D texture = LoadTexture(texturePath.c_str());
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
    textures.push_back(texture);
  }

  return textures;
}
