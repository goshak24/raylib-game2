#ifndef GAME_STATE_H
#define GAME_STATE_H

enum class Scene {
    INIT,
    DINING_HALL,
    HOSPITAL_MIKHAIL,
    HOSPITAL_SERGEI,
    RETURN_MIKHAIL,
    NIGHT_INCIDENT,
    DESK_END
};

class GameState {
public:
    static GameState& GetInstance();

    Scene currentScene;
    int money;
    int morphineCount;
    int daysPassed;

    // Reset state for a new game
    void Reset();

private:
    GameState();
    ~GameState() = default;
};

#endif // GAME_STATE_H
