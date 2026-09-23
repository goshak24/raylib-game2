#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include <vector>

struct DialogueChoice {
    std::string text;
    std::string nextNodeId;
    std::string behaviorTag; // e.g., "MERCY", "CURIOSITY"
    std::string eventTarget; // e.g., "Mikhail"
};

struct DialogueNode {
    std::string id;
    std::string speaker;
    std::string text;
    std::vector<DialogueChoice> choices;
};

#endif // DIALOGUE_H
