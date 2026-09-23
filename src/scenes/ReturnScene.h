#ifndef RETURN_SCENE_H
#define RETURN_SCENE_H

#include "../core/GameState.h"
#include "../core/MemoryTracker.h"
#include "raylib.h"
#include <string>

class ReturnScene {
public:
    void Init();
    void Update();
    void Draw();

private:
    int step = 0;
    std::string customDialogue = "";
};

#endif // RETURN_SCENE_H
