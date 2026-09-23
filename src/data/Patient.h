#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

struct Patient {
    std::string id;
    std::string name;
    std::string description;

    // Simple state
    bool isBleeding;
    int painLevel; // 0 to 10

    // Specific observations
    std::string headObs;
    std::string chestObs;
    std::string armObs;
    std::string legObs;
};

#endif // PATIENT_H
