#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class AssetManager {
public:
  void hello();

  // Requires an open Raylib window. The caller owns and unloads the textures.
  std::vector<Texture2D> LoadAsset(const std::string &path, const std::string &animation);
};
