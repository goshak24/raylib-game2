#ifndef TREATMENT_SYSTEM_H
#define TREATMENT_SYSTEM_H

#include "../data/Patient.h"
#include "../core/GameState.h"
#include <string>

class TreatmentSystem {
public:
    static bool TreatMorphine(Patient& patient, GameState& state);
    static bool TreatCleanDress(Patient& patient);
    static std::string Observe(const Patient& patient, const std::string& bodyPart);
};

#endif // TREATMENT_SYSTEM_H
