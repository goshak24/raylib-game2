#include "../src/core/MemoryTracker.h"
#include <cassert>
#include <iostream>

int main() {
    MemoryTracker& mem = MemoryTracker::GetInstance();
    mem.Clear();

    mem.AddEvent("MERCY", "gave_morphine", "MIKHAIL", 2);
    assert(mem.HasEvent("MERCY", "MIKHAIL"));
    assert(mem.GetEventStrength("MERCY", "MIKHAIL") == 2);
    assert(mem.IsCompassionate("MIKHAIL") == true);
    assert(mem.KeptPromises("MIKHAIL") == false);

    std::cout << "Memory tests passed." << std::endl;
    return 0;
}
