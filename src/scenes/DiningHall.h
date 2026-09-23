#ifndef DINING_HALL_H
#define DINING_HALL_H

#include "../core/GameState.h"
#include "../core/MemoryTracker.h"
#include "raylib.h"

class DiningHall {
public:
    void Init();
    void Update();
    void Draw();

private:
    int step = 0; // 0 = Enter, 1 = Caterer, 2 = Letter, 3 = End
    bool foodReceived = false;
};

#endif // DINING_HALL_H
