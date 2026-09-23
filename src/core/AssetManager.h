#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "raylib.h"
#include <map>
#include <string>

class AssetManager {
public:
    static AssetManager& GetInstance() {
        static AssetManager instance;
        return instance;
    }

    void LoadTexture2D(const std::string& name, const std::string& path);
    Texture2D GetTexture2D(const std::string& name);
    void UnloadAll();

private:
    AssetManager() = default;
    ~AssetManager() = default;

    std::map<std::string, Texture2D> textures;
};

#endif
