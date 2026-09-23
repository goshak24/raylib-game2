#include "raylib.h"
#include "core/GameState.h"
#include "core/MemoryTracker.h"
#include "scenes/DiningHall.h"
#include "scenes/HospitalScene.h"
#include "scenes/ReturnScene.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "The Last Meal - Initialization");
    SetTargetFPS(60);

    // Initial systems setup
    GameState& state = GameState::GetInstance();
    state.Reset();
    state.currentScene = Scene::DINING_HALL;

    DiningHall diningHall;
    diningHall.Init();

    HospitalScene hospitalSceneMikhail;
    hospitalSceneMikhail.Init(false);

    HospitalScene hospitalSceneSergei;
    hospitalSceneSergei.Init(true);

    ReturnScene returnScene;
    returnScene.Init();

    while (!WindowShouldClose())
    {
        switch (state.currentScene) {
            case Scene::INIT:
            case Scene::DINING_HALL:
                diningHall.Update();
                break;
            case Scene::HOSPITAL_MIKHAIL:
                hospitalSceneMikhail.Update();
                break;
            case Scene::HOSPITAL_SERGEI:
                hospitalSceneSergei.Update();
                break;
            case Scene::RETURN_MIKHAIL:
                returnScene.Update();
                break;
            case Scene::DESK_END:
                // End state - nothing to update
                break;
            default:
                break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (state.currentScene) {
            case Scene::INIT:
            case Scene::DINING_HALL:
                diningHall.Draw();
                break;
            case Scene::HOSPITAL_MIKHAIL:
                hospitalSceneMikhail.Draw();
                break;
            case Scene::HOSPITAL_SERGEI:
                hospitalSceneSergei.Draw();
                break;
            case Scene::RETURN_MIKHAIL:
                returnScene.Draw();
                break;
            case Scene::DESK_END:
                DrawText("THE LAST MEAL - Vertical Slice Complete.", 150, 250, 25, RAYWHITE);
                DrawText("You are left with the consequences of your decisions.", 120, 300, 20, LIGHTGRAY);
                DrawText("[ESC] to Exit", 350, 400, 15, DARKGRAY);
                break;
            default:
                DrawText("Scene Not Implemented Yet", 190, 200, 20, LIGHTGRAY);
                break;
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
