#include "../src/systems/TreatmentSystem.h"
#include "../src/data/Patient.h"
#include "../src/core/GameState.h"
#include <cassert>
#include <iostream>

int main() {
    GameState& state = GameState::GetInstance();
    state.morphineCount = 1;

    Patient p;
    p.id = "MIKHAIL";
    p.painLevel = 8;
    p.isBleeding = true;
    p.legObs = "Bad leg";

    assert(TreatmentSystem::TreatCleanDress(p) == true);
    assert(p.isBleeding == false);

    assert(TreatmentSystem::TreatMorphine(p, state) == true);
    assert(state.morphineCount == 0);
    assert(p.painLevel == 0);

    assert(TreatmentSystem::TreatMorphine(p, state) == false);

    assert(TreatmentSystem::Observe(p, "LEG") == "Bad leg");

    std::cout << "Treatment tests passed." << std::endl;
    return 0;
}
