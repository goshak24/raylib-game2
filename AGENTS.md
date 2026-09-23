# Developer Guidelines (AGENTS.md)

1. **Raylib ONLY**: Use Raylib for all rendering, input, and audio. Do not migrate to another engine.
2. **C/C++ Standard Architecture**: Prefer standard, modular C/C++. Avoid a monolithic main file.
3. **Data-Driven**: Do not hardcode patients, dialogue, or events into gameplay logic. Use data structures (JSON, structs, or parsed text) loaded into memory.
4. **No Morality Meters**: Do not expose raw scores like "Compassion +1". Save behavioral events to a tracker and alter dialogue based on presence of events.
5. **Memory is Key**: Ensure interactions with patients update their state/memory log. Returning patients must reflect past choices.
6. **No Spurious Randomness**: State changes should rely on player behavior and world conditions.
7. **Clean Architecture**: Follow the established `src/`, `assets/`, `data/` structure.
8. **UI Restraint**: Ensure UI fits the in-world presentation. No floating damage text or standard HUDs. Use paper, labels, notes.
