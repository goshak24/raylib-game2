#include "AssetManager.h"
#include <iostream>

void AssetManager::LoadTexture2D(const std::string& name, const std::string& path) {
    if (textures.find(name) == textures.end()) {
        Texture2D tex = LoadTexture(path.c_str());
        textures[name] = tex;
    }
}

Texture2D AssetManager::GetTexture2D(const std::string& name) {
    return textures[name];
}

void AssetManager::UnloadAll() {
    for (auto& pair : textures) {
        UnloadTexture(pair.second);
    }
    textures.clear();
}
