#include "TreatmentSystem.h"

bool TreatmentSystem::TreatMorphine(Patient& patient, GameState& state) {
    if (state.morphineCount > 0) {
        state.morphineCount--;
        patient.painLevel = 0; // Pain relief
        return true;
    }
    return false; // Out of morphine
}

bool TreatmentSystem::TreatCleanDress(Patient& patient) {
    if (patient.isBleeding) {
        patient.isBleeding = false;
        return true;
    }
    return false;
}

std::string TreatmentSystem::Observe(const Patient& patient, const std::string& bodyPart) {
    if (bodyPart == "LEG") {
        return patient.legObs;
    } else if (bodyPart == "HEAD") {
        return patient.headObs;
    } else if (bodyPart == "CHEST") {
        return patient.chestObs;
    } else if (bodyPart == "ARM") {
        return patient.armObs;
    }
    return "No obvious injuries.";
}
