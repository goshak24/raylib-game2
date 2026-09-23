#include "MemoryTracker.h"

MemoryTracker& MemoryTracker::GetInstance() {
    static MemoryTracker instance;
    return instance;
}

void MemoryTracker::AddEvent(const std::string& type, const std::string& context, const std::string& target, int strength) {
    events.push_back({type, context, target, strength});
}

bool MemoryTracker::HasEvent(const std::string& type, const std::string& target) const {
    for (const auto& ev : events) {
        if (ev.type == type && ev.target == target) {
            return true;
        }
    }
    return false;
}

int MemoryTracker::GetEventStrength(const std::string& type, const std::string& target) const {
    int total = 0;
    for (const auto& ev : events) {
        if (ev.type == type && ev.target == target) {
            total += ev.strength;
        }
    }
    return total;
}

bool MemoryTracker::IsCompassionate(const std::string& target) const {
    return GetEventStrength("MERCY", target) > 0 || GetEventStrength("EMOTIONAL_INVOLVEMENT", target) > 0;
}

bool MemoryTracker::KeptPromises(const std::string& target) const {
    return HasEvent("KEPT_PROMISE", target);
}

void MemoryTracker::Clear() {
    events.clear();
}
