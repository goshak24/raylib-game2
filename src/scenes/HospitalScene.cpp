#include "HospitalScene.h"
#include "../systems/TreatmentSystem.h"
#include "../core/AssetManager.h"

void HospitalScene::SetupMikhail() {
    currentPatient.id = "MIKHAIL";
    currentPatient.name = "Mikhail";
    currentPatient.description = "Young soldier, visibly frightened.";
    currentPatient.isBleeding = true;
    currentPatient.painLevel = 8;
    currentPatient.legObs = "Shrapnel wound. Bleeding appears controlled. Severe pain. Swelling around the wound.";
    currentPatient.headObs = "Pale face. Sweating.";
    currentPatient.chestObs = "Breathing rapidly.";
    currentPatient.armObs = "No obvious injuries.";
}

void HospitalScene::SetupSergei() {
    currentPatient.id = "SERGEI";
    currentPatient.name = "Sergei";
    currentPatient.description = "Older soldier. Calm exterior but requests morphine.";
    currentPatient.isBleeding = false;
    currentPatient.painLevel = 7;
    currentPatient.legObs = "Old scar, no new injuries.";
    currentPatient.headObs = "Stoic expression.";
    currentPatient.chestObs = "Steady breathing.";
    currentPatient.armObs = "Gunshot wound. Cleaned but clearly painful.";
}

void HospitalScene::Init(bool isSergei) {
    step = 0;
    activePatientIsSergei = isSergei;
    examObservation = "";
    feedbackMsg = "";

    if (isSergei) {
        SetupSergei();
    } else {
        SetupMikhail();
    }
    AssetManager::GetInstance().LoadTexture2D("reference_character", "assets/sprites/reference_character.png");
}

void HospitalScene::Update() {
    GameState& state = GameState::GetInstance();
    MemoryTracker& mem = MemoryTracker::GetInstance();

    if (step == 0) {
        Vector2 mouse = GetMousePosition();

        // Very basic hover zones
        hoverBodyPart = "";
        if (CheckCollisionPointRec(mouse, { 350, 150, 100, 50 })) hoverBodyPart = "HEAD";
        if (CheckCollisionPointRec(mouse, { 350, 200, 100, 100 })) hoverBodyPart = "CHEST";
        if (CheckCollisionPointRec(mouse, { 250, 200, 100, 100 })) hoverBodyPart = "ARM";
        if (CheckCollisionPointRec(mouse, { 350, 300, 100, 150 })) hoverBodyPart = "LEG";

        // Interactions
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && hoverBodyPart != "") {
            examObservation = TreatmentSystem::Observe(currentPatient, hoverBodyPart);
        }

        // Treatments
        if (IsKeyPressed(KEY_M)) { // Morphine
            if (TreatmentSystem::TreatMorphine(currentPatient, state)) {
                mem.AddEvent("MERCY", "gave_morphine", currentPatient.id, 2);
                feedbackMsg = "Administered Morphine.";
            } else {
                feedbackMsg = "No Morphine left.";
            }
        }

        if (IsKeyPressed(KEY_C)) { // Clean & Dress
            TreatmentSystem::TreatCleanDress(currentPatient);
            mem.AddEvent("MEDICAL_DUTY", "cleaned_wound", currentPatient.id, 1);
            feedbackMsg = "Cleaned and Dressed Wound.";
        }

        // Dialogue Choices for Mikhail
        if (!activePatientIsSergei) {
            if (IsKeyPressed(KEY_ONE)) {
                mem.AddEvent("HONESTY", "admit_uncertainty", currentPatient.id, 1);
                feedbackMsg = "Mikhail: Do you think I'll walk again?\nYou: I don't know yet.";
                step = 1; // move to finish
            }
            if (IsKeyPressed(KEY_TWO)) {
                mem.AddEvent("REASSURANCE", "promised_walk", currentPatient.id, 1);
                mem.AddEvent("KEPT_PROMISE", "check_leg_tomorrow", currentPatient.id, 1); // setting up promise
                feedbackMsg = "Mikhail: Do you think I'll walk again?\nYou: Yes. We'll check it tomorrow.";
                step = 1;
            }
            if (IsKeyPressed(KEY_THREE)) {
                mem.AddEvent("EMOTIONAL_INVOLVEMENT", "ask_about_family", currentPatient.id, 2);
                feedbackMsg = "You: Where are you from?\nMikhail: [Talks about his mother's bread...]";
                step = 1;
            }
        } else {
            // Dialogue Choices for Sergei
            if (IsKeyPressed(KEY_ONE)) {
                mem.AddEvent("CURIOSITY", "asked_fear", currentPatient.id, 1);
                feedbackMsg = "Sergei admits: \"I'm afraid.\"";
                step = 1;
            }
            if (IsKeyPressed(KEY_SPACE)) {
                step = 1;
            }
        }
    }
    else if (step == 1) {
        if (IsKeyPressed(KEY_SPACE)) {
            if (!activePatientIsSergei) {
                state.currentScene = Scene::HOSPITAL_SERGEI;
            } else {
                state.currentScene = Scene::RETURN_MIKHAIL;
            }
        }
    }
}

void HospitalScene::Draw() {
    ClearBackground({ 30, 30, 35, 255 }); // Darker hospital interior
    Texture2D charTex = AssetManager::GetInstance().GetTexture2D("reference_character");
    if (charTex.id != 0) {
        DrawTexturePro(charTex, {0, 0, (float)charTex.width, (float)charTex.height}, {400, 150, 200, 300}, {0, 0}, 0.0f, WHITE);
    }
    GameState& state = GameState::GetInstance();

    DrawText("WARD", 30, 30, 20, LIGHTGRAY);
    DrawText(TextFormat("Morphine: %d", state.morphineCount), 620, 30, 20, LIGHTGRAY);

    DrawText(currentPatient.name.c_str(), 350, 100, 20, RAYWHITE);
    DrawText(currentPatient.description.c_str(), 350, 125, 15, GRAY);

    // Draw rudimentary body zones
    DrawRectangleLines(350, 150, 100, 50, hoverBodyPart == "HEAD" ? WHITE : DARKGRAY);
    DrawRectangleLines(350, 200, 100, 100, hoverBodyPart == "CHEST" ? WHITE : DARKGRAY);
    DrawRectangleLines(250, 200, 100, 100, hoverBodyPart == "ARM" ? WHITE : DARKGRAY);
    DrawRectangleLines(350, 300, 100, 150, hoverBodyPart == "LEG" ? WHITE : DARKGRAY);

    if (examObservation != "") {
        DrawText("OBSERVATION:", 50, 250, 15, GRAY);
        DrawText(examObservation.c_str(), 50, 275, 15, LIGHTGRAY);
    }

    if (feedbackMsg != "") {
        DrawText(feedbackMsg.c_str(), 50, 350, 15, WHITE);
    }

    if (step == 0) {
        DrawText("[Hover body] to Examine", 50, 450, 15, DARKGRAY);
        DrawText("[M] Administer Morphine  [C] Clean & Dress", 50, 475, 15, DARKGRAY);

        if (!activePatientIsSergei) {
            DrawText("Mikhail asks: \"Do you think I'll walk again?\"", 50, 525, 15, RAYWHITE);
            DrawText("[1] \"I don't know yet.\"", 50, 550, 15, LIGHTGRAY);
            DrawText("[2] \"Yes. We'll check it tomorrow.\"", 50, 570, 15, LIGHTGRAY);
            DrawText("[3] \"Where are you from?\"", 50, 590, 15, LIGHTGRAY);
        } else {
            DrawText("[1] Ask about his stoicism", 50, 550, 15, LIGHTGRAY);
            DrawText("[SPACE] Finish treatment", 50, 570, 15, LIGHTGRAY);
        }
    } else {
        DrawText("[SPACE] Continue working", 50, 550, 20, GREEN);
    }
}
