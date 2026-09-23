#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <string>
#include <vector>
#include <map>

struct BehaviorEvent {
    std::string type;
    std::string context;
    std::string target;
    int strength;
};

class MemoryTracker {
public:
    static MemoryTracker& GetInstance();

    void AddEvent(const std::string& type, const std::string& context, const std::string& target, int strength);
    bool HasEvent(const std::string& type, const std::string& target) const;
    int GetEventStrength(const std::string& type, const std::string& target) const;

    // Check specific player narrative behaviors
    bool IsCompassionate(const std::string& target) const;
    bool KeptPromises(const std::string& target) const;

    void Clear();

private:
    MemoryTracker() = default;
    ~MemoryTracker() = default;

    std::vector<BehaviorEvent> events;
};

#endif // MEMORY_TRACKER_H
