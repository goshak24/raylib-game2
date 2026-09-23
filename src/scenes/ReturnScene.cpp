#include "ReturnScene.h"
#include "../core/AssetManager.h"

void ReturnScene::Init() {
    step = 0;
    customDialogue = "";
    AssetManager::GetInstance().LoadTexture2D("winter_night", "assets/environments/winter_night.png");
}

void ReturnScene::Update() {
    GameState& state = GameState::GetInstance();
    MemoryTracker& mem = MemoryTracker::GetInstance();

    if (step == 0) {
        if (IsKeyPressed(KEY_SPACE)) {
            // Build custom dialogue based on memory
            if (mem.HasEvent("REASSURANCE", "MIKHAIL")) {
                customDialogue = "Mikhail: Doctor... you remember me?\nYou said you'd look at my leg again.";
            } else if (mem.HasEvent("EMOTIONAL_INVOLVEMENT", "MIKHAIL")) {
                customDialogue = "Mikhail: Doctor.\nMy mother sent something. She... heard you asked about her.";
            } else if (mem.HasEvent("MERCY", "MIKHAIL")) {
                customDialogue = "Mikhail: Doctor... thanks for the medicine earlier.\nIt helped.";
            } else {
                customDialogue = "Mikhail: Doctor... my leg still hurts.\n[He seems guarded, expecting little.]";
            }
            step = 1;
        }
    } else if (step == 1) {
        if (IsKeyPressed(KEY_SPACE)) {
            step = 2; // Transition out or end slice
        }
    } else if (step == 2) {
        if (IsKeyPressed(KEY_SPACE)) {
            state.currentScene = Scene::DESK_END;
        }
    }
}

void ReturnScene::Draw() {
    Texture2D bg = AssetManager::GetInstance().GetTexture2D("winter_night");
    if (bg.id != 0) {
        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, 800, 600}, {0, 0}, 0.0f, WHITE);
        DrawRectangle(0, 0, 800, 600, {0, 0, 0, 200}); // heavy dim for night
    } else {
        ClearBackground({ 25, 25, 30, 255 }); // Fallback
    }

    DrawText("LATER IN THE WARD", 30, 30, 20, LIGHTGRAY);

    if (step == 0) {
        DrawText("You are doing paperwork when a familiar face appears.", 50, 200, 20, RAYWHITE);
        DrawText("[SPACE] Look up", 50, 500, 20, DARKGRAY);
    } else if (step == 1) {
        DrawText(customDialogue.c_str(), 50, 200, 20, RAYWHITE);
        DrawText("[SPACE] Nod", 50, 500, 20, DARKGRAY);
    } else if (step == 2) {
        DrawText("Mikhail places a small photograph on your desk.", 50, 200, 20, RAYWHITE);
        DrawText("It's of his family. He leaves without another word.", 50, 230, 20, LIGHTGRAY);
        DrawText("[SPACE] Return to your desk", 50, 500, 20, DARKGRAY);
    }
}
