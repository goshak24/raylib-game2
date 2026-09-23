#include "DiningHall.h"
#include "../core/AssetManager.h"

void DiningHall::Init() {
    step = 0;
    foodReceived = false;
    AssetManager::GetInstance().LoadTexture2D("war_hospital", "assets/environments/war_hospital.png");
}

void DiningHall::Update() {
    GameState& state = GameState::GetInstance();
    MemoryTracker& mem = MemoryTracker::GetInstance();

    if (step == 0) {
        if (IsKeyPressed(KEY_SPACE)) step = 1;
    }
    else if (step == 1) {
        if (IsKeyPressed(KEY_SPACE)) {
            foodReceived = true;
            step = 2;
        }
    }
    else if (step == 2) {
        if (IsKeyPressed(KEY_ONE)) {
            // Send 20
            state.money -= 20;
            mem.AddEvent("FAMILY_DUTY", "sent_20", "family", 2);
            step = 3;
        }
        else if (IsKeyPressed(KEY_TWO)) {
            // Send 10
            state.money -= 10;
            mem.AddEvent("FAMILY_DUTY", "sent_10", "family", 1);
            step = 3;
        }
        else if (IsKeyPressed(KEY_THREE)) {
            // Send Nothing
            mem.AddEvent("SELF_PRESERVATION", "sent_0", "family", 1);
            step = 3;
        }
    }
    else if (step == 3) {
        if (IsKeyPressed(KEY_SPACE)) {
            state.currentScene = Scene::HOSPITAL_MIKHAIL;
        }
    }
}

void DiningHall::Draw() {
    Texture2D bg = AssetManager::GetInstance().GetTexture2D("war_hospital");
    if (bg.id != 0) {
        DrawTexturePro(bg, {0, 0, (float)bg.width, (float)bg.height}, {0, 0, 800, 600}, {0, 0}, 0.0f, WHITE);
        DrawRectangle(0, 0, 800, 600, {0, 0, 0, 150}); // dim background
    } else {
        ClearBackground({ 40, 42, 45, 255 }); // Fallback
    }
    GameState& state = GameState::GetInstance();

    DrawText("DINING HALL", 30, 30, 20, LIGHTGRAY);
    DrawText(TextFormat("Money: %d", state.money), 650, 30, 20, LIGHTGRAY);

    if (step == 0) {
        DrawText("You enter the dining hall. The air is cold, but the kitchen is warm.", 50, 200, 20, RAYWHITE);
        DrawText("[SPACE] Walk to the counter", 50, 500, 20, DARKGRAY);
    }
    else if (step == 1) {
        DrawText("Caterer: \"Doctor. Soup today.\"", 50, 200, 20, RAYWHITE);
        DrawText("[SPACE] Take food and sit down", 50, 500, 20, DARKGRAY);
    }
    else if (step == 2) {
        DrawText("You sit with your soup. A letter from your family rests on the table.", 50, 150, 20, LIGHTGRAY);

        DrawRectangle(300, 200, 300, 250, RAYWHITE); // Letter UI
        DrawText("Coal has become expensive.", 320, 220, 15, BLACK);
        DrawText("We need help for the winter.", 320, 250, 15, BLACK);

        DrawText("[1] Send 20 Rubles", 50, 480, 20, DARKGRAY);
        DrawText("[2] Send 10 Rubles", 50, 510, 20, DARKGRAY);
        DrawText("[3] Send Nothing", 50, 540, 20, DARKGRAY);
    }
    else if (step == 3) {
        DrawText("You finish your meal. The hospital awaits.", 50, 200, 20, RAYWHITE);
        DrawText("[SPACE] Go to the Ward", 50, 500, 20, DARKGRAY);
    }
}
