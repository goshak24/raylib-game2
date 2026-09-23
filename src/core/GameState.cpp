#include "GameState.h"

GameState& GameState::GetInstance() {
    static GameState instance;
    return instance;
}

GameState::GameState() {
    Reset();
}

void GameState::Reset() {
    currentScene = Scene::INIT;
    money = 50;
    morphineCount = 2;
    daysPassed = 1;
}
