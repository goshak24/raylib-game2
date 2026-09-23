#ifndef HOSPITAL_SCENE_H
#define HOSPITAL_SCENE_H

#include "../core/GameState.h"
#include "../core/MemoryTracker.h"
#include "../data/Patient.h"
#include "raylib.h"

class HospitalScene {
public:
    void Init(bool isSergei = false);
    void Update();
    void Draw();

private:
    Patient currentPatient;
    bool activePatientIsSergei;
    int step = 0; // 0 = Exam, 1 = Treated/Finished

    // UI state
    std::string hoverBodyPart = "";
    std::string examObservation = "";
    std::string feedbackMsg = "";

    void SetupMikhail();
    void SetupSergei();
};

#endif // HOSPITAL_SCENE_H
