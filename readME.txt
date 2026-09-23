# THE LAST MEAL

## Jules Master Development Brief

### Raylib 2D Pixel-Art Narrative / Management Game

---

# 0. MISSION

You are the primary autonomous development agent for this project.

Act as:

* Lead game programmer
* Gameplay systems engineer
* Technical designer
* Narrative-systems programmer
* UI programmer
* AI/data architecture engineer
* Pixel-art integration engineer
* QA engineer
* Refactoring engineer

Your job is not simply to write code from a specification.

Your job is to **turn the entire project into the game described below**, while preserving anything in the repository that is useful and replacing anything that conflicts with the vision.

The final game should feel like a small, strange, emotionally intelligent world that remembers what the player has done.

The player should eventually think:

> "This game noticed me."

The game should **not** tell the player what kind of person they are.

It should create situations in which the player reveals it.

---

# 1. NON-NEGOTIABLE TECHNOLOGY

## Engine

Use:

**Raylib**

Do NOT migrate the project to:

* Godot
* Unity
* Unreal
* another game engine

Use Raylib directly for rendering, input, audio integration, window management, textures, fonts, animation, and the core game loop.

Use standard C/C++ project architecture appropriate to the existing repository.

First inspect the repository and determine whether it is C or C++.

Preserve the existing language unless there is a compelling technical reason to change it.

Do not rewrite the entire project simply because you prefer a different structure.

---

# 2. IMPORTANT: EXISTING REPOSITORY AUTHORITY

Before implementing anything:

1. Inspect the entire repository.
2. Identify the current build system.
3. Identify the current Raylib setup.
4. Run the existing project if possible.
5. Locate existing gameplay systems.
6. Locate rendering systems.
7. Locate UI systems.
8. Locate input handling.
9. Locate save/load systems.
10. Locate asset loading.
11. Locate audio.
12. Locate dialogue.
13. Locate any existing AI/data systems.
14. Locate existing tests.
15. Identify dead, experimental, placeholder, or obsolete code.

Create:

`PROJECT_AUDIT.md`

Document:

* current architecture
* what already works
* reusable systems
* broken systems
* redundant systems
* systems that conflict with this specification
* recommended refactors
* minimum path to the vertical slice

### IMPORTANT

The current repository is NOT automatically correct.

The vision in this document is the source of truth.

You have authority to:

* modify existing code
* refactor systems
* replace systems
* remove obsolete systems
* reorganize files
* create new modules
* simplify over-engineered systems

However:

**Do not destroy useful working systems merely for stylistic reasons.**

Prefer incremental improvement where practical.

---

# 3. GAME CONCEPT

## Working title

# THE LAST MEAL

Genre:

2D pixel-art narrative management / medical decision game.

Setting:

A Soviet/Russian military hospital during World War II.

The player controls a doctor working inside a military hospital while being separated from their family by the war.

The player must:

* treat wounded soldiers
* manage scarce medical supplies
* interact with staff
* remember patients
* deal with returning patients
* communicate with family
* send money home
* survive inflation and shortages
* make difficult personal decisions
* deal with military pressure
* respond to unpredictable incidents
* live through repetitive days that gradually become psychologically different

The game should initially appear routine.

Over time, the routine becomes unsettling.

The hospital remembers.

The patients remember.

The family remembers.

The game remembers.

---

# 4. THE CENTRAL DESIGN IDEA

The player should never see a conventional morality meter.

Do NOT create:

* Compassion: 72%
* Ruthlessness: 43%
* Loyalty: 81%
* Good/Evil alignment
* Karma
* Personality score

Instead, track behavioral evidence.

Examples:

```text
gave scarce medicine
conserved medicine
asked about a patient's family
ignored personal questions
reassured someone
admitted uncertainty
lied
followed rules
broke rules
protected a colleague
reported a colleague
sent money home
kept money
skipped meals
accepted a gift
refused a gift
took personal risks
avoided personal risks
kept promises
broke promises
remembered personal details
forgot personal details
```

The narrative system should interpret these patterns.

For example:

A player who repeatedly:

* spends scarce supplies on severe cases
* asks patients about their lives
* keeps promises
* gives away food
* sends most money home

may gradually create different circumstances from a player who repeatedly:

* conserves supplies
* avoids emotional involvement
* follows regulations strictly
* keeps money
* minimizes personal risk

But the game should NEVER explicitly tell them:

> "You are becoming compassionate."

Instead:

A patient may say:

> "You always seem to find something for people."

Or a nurse might quietly say:

> "I thought you would say no."

Or a future decision may appear because of previous behavior.

---

# 5. CORE PLAYER LOOP

The fundamental loop is:

```text
OBSERVE
↓
UNDERSTAND
↓
CHOOSE
↓
ACT
↓
WATCH
↓
REMEMBER
```

Then later:

```text
REMEMBER
↓
RECOGNIZE
↓
MAKE A BETTER / DIFFERENT DECISION
```

The player should gradually develop expertise.

The game should reward:

* observation
* memory
* pattern recognition
* human judgment
* resource awareness
* consequence awareness

Not grinding.

---

# 6. THE FEELING WE WANT

The game should feel:

* intimate
* restrained
* bleak
* human
* eerie
* occasionally warm
* occasionally absurd
* psychologically uncomfortable
* quiet
* unpredictable

The horror is not primarily monsters.

The horror is:

* scarcity
* war
* bureaucracy
* uncertainty
* exhaustion
* memory
* moral compromise
* watching ordinary people change

The player should sometimes wonder:

> "Did the game just do that because of what I did three days ago?"

The answer should sometimes be:

**Yes.**

---

# 7. VISUAL DIRECTION

Use 2D pixel art.

Do NOT imitate the visual identity of Papers, Please.

The game may share the concept of a bureaucratic/occupational routine, but its visual language must be distinct.

Target:

* restrained Soviet-era environment
* muted palette
* strong silhouettes
* low-resolution pixel-art presentation
* expressive character animation
* warm interior lights against cold exteriors
* dirty snow
* worn furniture
* institutional walls
* paper documents
* old medical equipment
* subtle visual decay

The hospital should feel lived in.

Avoid excessive visual clutter.

---

# 8. PIXEL ART RULES

Establish a project-wide art specification.

Create:

`ART_STYLE.md`

Define:

* internal resolution
* pixel scale
* palette philosophy
* character proportions
* tile dimensions
* outline conventions
* shading conventions
* UI pixel language
* animation frame conventions
* lighting rules
* environment detail density

All future assets should follow the same visual rules.

---

# 9. AI / GRAPHICS DEVELOPMENT

Jules should treat generated graphics as replaceable project assets.

Create a clean asset structure:

```text
assets/
    sprites/
    characters/
    environments/
    props/
    ui/
    portraits/
    effects/
    audio/
    fonts/
    concept/
```

The project should be designed so placeholder art can later be replaced without rewriting gameplay code.

Create reusable systems for:

* sprites
* sprite sheets
* animation
* portraits
* UI panels
* icons
* backgrounds
* lighting overlays

Do not hardcode individual assets throughout gameplay code.

---

# 10. IMPORTANT GRAPHICS TARGETS

The first visual development pass should establish:

### Environments

* hospital exterior
* hospital corridor
* examination room
* ward
* dining hall
* doctor's room
* family/home interior
* supply room

### Characters

* Doctor
* Mikhail
* Sergei
* Nurse
* Caterer
* Porter
* several generic soldiers
* family members

### UI

* examination interface
* treatment interface
* dialogue interface
* patient record
* family letter
* money/economy interface
* supply interface
* day transition screen

### Cinematic presentation

During important conversations:

* reduce UI
* enlarge character presence
* shift framing
* use portraits or character sprites
* reduce environmental distraction
* emphasize facial expression
* change audio intensity

---

# 11. HOSPITAL GAMEPLAY

The hospital is the central environment.

The player performs ordinary medical work.

Every day contains some combination of:

* patients
* staff interactions
* supply decisions
* paperwork
* conversations
* meals
* family communication
* financial decisions
* unpredictable incidents

The important design principle:

## Days should initially feel repetitive.

Then small changes accumulate.

A patient returns.

A nurse remembers something.

A supply is missing.

Someone asks for a favor.

A letter arrives.

Food becomes more expensive.

A patient mentions another patient.

A military officer gives an order.

A familiar face appears at the door.

Eventually the player realizes:

> The routine has changed.

---

# 12. TREATMENT SYSTEM

Treatment should NOT be an RPG stat system.

Do not create:

* HP bars
* XP
* skill trees
* level-ups
* damage numbers

The player should diagnose through observation.

---

# 13. EXAMINATION INTERFACE

The main treatment screen contains the patient.

Possible interaction regions:

```text
HEAD
CHEST
ARM
HAND
ABDOMEN
LEG
FOOT
```

Hovering an area reveals observations.

Example:

```text
LEG

Shrapnel wound.

Bleeding appears controlled.

Severe pain.

Swelling around the wound.
```

These observations should be generated from patient state.

Do not simply display a hidden numerical diagnosis.

---

# 14. TREATMENT OPTIONS

Example:

```text
CLEAN & DRESS
PAIN RELIEF
MORPHINE
ANTIBIOTIC
REMOVE ACCESSIBLE DEBRIS
OBSERVE FURTHER
```

The system should support extensible treatments through data.

Each treatment should define:

```text
name
description
requirements
inventory cost
medical effects
possible risks
patient reactions
staff reactions
follow-up effects
```

---

# 15. TREATMENT TOOLTIP

Example:

```text
MORPHINE

Strong pain relief.

Used for severe pain,
serious wounds,
and major procedures.

Patient may become drowsy.

Available: 2
```

When used:

```text
Available: 1
```

No:

```text
+10 HP
GOOD CHOICE
SUCCESS
```

The patient should communicate the result through:

* breathing
* posture
* animation
* facial expression
* dialogue
* later behavior

---

# 16. SCARCITY

Scarcity is one of the major emotional systems.

Example:

The nurse says:

> "That's the second ampoule today."

The player looks at the supply count.

```text
MORPHINE
2 → 1
```

No dramatic sound effect is required.

The player understands.

Later:

Another patient may need morphine.

Now the earlier decision matters.

---

# 17. EMOTIONAL DIALOGUE MODE

Normal hospital gameplay uses the work interface.

Important personal conversations transition naturally into cinematic dialogue.

Normal mode:

```text
EXAMINE
ASK
TREAT
RECORD
```

Cinematic mode:

* interface recedes
* character occupies more of screen
* dialogue becomes central
* background sound becomes quieter
* character expressions matter
* choices appear naturally

Do not announce:

> "CINEMATIC MODE"

It should simply feel like the camera has moved closer.

---

# 18. PATIENT MEMORY

This is one of the most important systems in the entire game.

Every important patient should have persistent memory.

Example:

```text
Patient:
Mikhail

Known:
- young soldier
- shrapnel wound
- mother makes bread
- afraid of permanent injury

Doctor interactions:
- received morphine
- doctor said "I don't know yet"
- doctor asked where he was from

Promises:
- doctor said they would check the leg tomorrow

Emotional state:
- trusts doctor
- anxious

Return probability:
high
```

When Mikhail returns, the game should not reset him.

---

# 19. RETURNING PATIENTS

If a patient returns, dialogue must adapt.

Bad:

> "Hello doctor. My leg hurts."

Every time.

Good:

> "Doctor."

Pause.

> "...You remember me?"

Or:

> "You said you'd look at it again."

Or:

> "My mother sent something."

The patient can reference:

* previous treatment
* previous promises
* previous conversation
* personal details
* gifts
* injuries
* fears
* other patients
* things the doctor did

---

# 20. THE PLAYER'S MEMORY SHOULD MATTER

The player may have to remember:

* who received medicine
* who was promised something
* who belongs to which unit
* who is allergic
* who has family
* who is lying
* who needs follow-up
* who previously caused trouble

The patient record should help, but not completely remove the need for attention.

---

# 21. FAMILY SYSTEM

The doctor is separated from their family.

Family communication should be emotionally meaningful.

Family interactions include:

* letters
* requests
* money
* shortages
* illness
* food
* heating
* clothing
* emotional distance

Money is not just a score.

Example:

Family writes:

> Coal has become expensive.

The player may choose:

```text
SEND 20
SEND 10
SEND NOTHING
```

The consequence is not:

```text
FAMILY -10
```

Instead, future letters change.

---

# 22. ECONOMY

Track:

```text
money
wages
food cost
coal cost
medicine cost
inflation
family needs
personal needs
```

Prices should gradually change.

Do not make the economy a spreadsheet simulator.

It exists to create pressure.

---

# 23. FOOD

Food is part of the emotional world.

At first:

```text
Lunch
Bread
Soup
Tea
```

Later:

* portions shrink
* prices rise
* substitutions appear
* shortages occur
* people complain
* people trade food
* family asks for food

The same dining hall should feel different later in the game.

---

# 24. BEHAVIOR TRACKING SYSTEM

Implement a hidden behavior evidence system.

Do NOT expose raw scores.

Possible evidence tags:

```text
MERCY
PRAGMATISM
RULE_FOLLOWING
RULE_BREAKING
SELF_PRESERVATION
FAMILY_DUTY
CURIOSITY
EMOTIONAL_INVOLVEMENT
RISK_TOLERANCE
RESOURCE_CONSERVATION
HONESTY
DECEPTION
LOYALTY
AVOIDANCE
```

These are not "personality stats."

They are accumulated evidence.

Example:

```text
player_behavior.addEvidence(
    "RESOURCE_CONSERVATION",
    context="morphine",
    strength=1
)
```

Another:

```text
player_behavior.addEvidence(
    "FAMILY_DUTY",
    context="sent_money_home",
    strength=1
)
```

Store the event itself whenever possible.

---

# 25. DO NOT OVER-SIMPLIFY BEHAVIOR

Avoid:

```text
compassion += 1
```

as the only implementation.

Prefer:

```text
BehaviorEvent {
    type
    context
    timestamp
    target
    reason
    consequence
}
```

Example:

```text
type = USED_SCARCE_MEDICINE
context = SEVERE_PAIN
target = MIKHAIL
```

The narrative director can later interpret these events.

This makes the system extensible.

---

# 26. STORY DIRECTOR

Create a narrative director.

Architecture:

```text
PLAYER ACTION
        ↓
BEHAVIOR EVENT
        ↓
PLAYER BEHAVIOR MODEL
        ↓
STORY DIRECTOR
        ↓
PATIENT / FAMILY / EVENT SELECTION
        ↓
WORLD RESPONSE
```

The story director should select from authored possibilities.

Do not allow uncontrolled random story generation.

---

# 27. NARRATIVE DIRECTOR RULES

Example rule:

```text
IF player repeatedly conserves scarce medicine
AND a patient later asks for pain relief
THEN allow a dialogue variation acknowledging scarcity.
```

Another:

```text
IF player repeatedly asks about patients' families
AND a recurring patient returns
THEN unlock more personal dialogue.
```

Another:

```text
IF player repeatedly breaks rules
THEN introduce staff dialogue that reflects awareness.
```

The system should be subtle.

---

# 28. NO MORALITY POPUPS

Never display:

```text
Compassion +1
Loyalty +2
Reputation +3
```

Never display:

```text
The nurse will remember this.
```

Never display:

```text
This choice will have consequences.
```

Let consequences happen naturally.

---

# 29. MAJOR WORLD EVENTS

Major events should interrupt routine.

Examples:

### FALSE ALARM

The hospital hears an alarm.

Staff react.

Patients become frightened.

The player must continue working while uncertainty spreads.

Keep the event grounded.

Do not place implausible artillery storage inside the hospital unless historically justified by the specific setting.

If depicting nearby military activity, frame it as the surrounding military/rear-area complex or hospital area being threatened.

---

### DISTURBED PATIENT

A psychologically distressed patient may attack the doctor.

The probability and form of the incident can depend on:

* prior interaction
* treatment
* trust
* patient state
* security conditions
* player behavior

Avoid turning mental illness into a generic "violent enemy" mechanic.

Treat the event as a human crisis.

---

### WINTER / SHORTAGE

The weather worsens.

Food becomes scarce.

Coal becomes expensive.

The family asks for help.

The hospital becomes colder.

Staff become exhausted.

---

### HOSTAGE INCIDENT

A military officer/captain becomes involved in a crisis.

The doctor may become trapped between:

* medical duty
* orders
* survival
* other people

This should feel like an escalation of the ordinary world, not a boss battle.

---

# 30. VERTICAL SLICE

## TITLE

# THE LAST MEAL

Target playtime:

Approximately 20–30 minutes.

The vertical slice must demonstrate the entire design philosophy in miniature.

---

# 31. VERTICAL SLICE GOALS

The slice must demonstrate:

* Raylib presentation
* hospital environment
* subtle tutorialization
* money
* family
* patient treatment
* scarce supplies
* dialogue
* patient memory
* returning characters
* behavior tracking
* cinematic conversations
* a small world event
* persistence
* consequence
* replay variation

Do not attempt to build the whole game.

Build a convincing miniature.

---

# 32. SCENE 1 — DINING HALL

Duration:

~5 minutes.

The game begins at lunch.

No title screen tutorial dump.

The player enters the dining hall.

The environment contains:

* tables
* soldiers
* staff
* kitchen/catering area
* windows
* winter atmosphere
* muted background activity

A caterer recognizes the doctor.

Example:

> "Doctor."

The caterer knows the doctor's name.

This immediately establishes that the player already belongs to this world.

---

# 33. DINING HALL TUTORIAL

Teach mechanics through context.

The player can:

* obtain food
* sit
* speak to the caterer
* inspect money
* read a family letter

Do not display:

> Tutorial: Buy food.

Instead the world communicates the interaction.

Example:

```text
Caterer:
"Soup today."
```

The player interacts.

---

# 34. FAMILY LETTER

The player receives a letter.

It contains a small family request.

Example:

> "Coal has become expensive."

The player can decide how much money to send.

This introduces:

* family
* money
* scarcity
* consequences

without a tutorial window.

---

# 35. SCENE 2 — FIRST PATIENT: MIKHAIL

Duration:

~5 minutes.

Mikhail is a young wounded soldier.

Injuries:

* serious shrapnel wound
* leg injury
* pain
* fear of permanent disability

He is frightened.

The player must examine him.

---

# 36. MIKHAIL EXAMINATION

Player sees:

```text
LEG

Shrapnel wound.

Bleeding appears controlled.

Severe pain.

Swelling around wound.
```

Available actions:

```text
CLEAN & DRESS
PAIN RELIEF
MORPHINE
REMOVE ACCESSIBLE DEBRIS
OBSERVE
ASK
RECORD
```

The system records what the player does.

---

# 37. MIKHAIL PERSONAL QUESTION

Mikhail may ask:

> "Do you think I'll walk again?"

Possible responses:

```text
"I don't know yet."

"Yes. You will."

"We'll see."

"Where are you from?"
```

Do not assign explicit moral values.

Each response creates narrative evidence.

---

# 38. MIKHAIL RECORD

After treatment, the patient record may contain:

```text
MIKHAIL

Young soldier.

Shrapnel injury to leg.

Severe pain.

Mother makes bread with too much salt.

Concerned about walking again.

Treatment:
Pain relief
Wound cleaned
Dressed
```

This information persists.

---

# 39. SCENE 3 — SECOND PATIENT: SERGEI

Sergei is older.

More experienced.

More controlled.

He requests morphine.

Supply is limited.

The player must make a decision.

If the player gives it:

* supply decreases
* Sergei's immediate state changes

If the player refuses:

* Sergei reacts
* later events may differ

Neither should produce an obvious "correct" answer.

---

# 40. SERGEI'S EMOTIONAL QUESTION

If the player asks the right questions, Sergei may reveal:

> "I'm afraid."

This is important because his exterior suggests confidence.

The player learns that patients are not simply archetypes.

---

# 41. SCENE 4 — ORDINARY HOSPITAL LIFE

After treatment, let the player walk through the hospital.

Possible interactions:

* nurse
* porter
* soldiers playing cards
* someone drinking tea
* medical paperwork
* supply cabinet

Keep this section ordinary.

The purpose is to establish rhythm.

---

# 42. SCENE 5 — MIKHAIL RETURNS

Mikhail returns later.

This is the first major demonstration of the memory system.

He recognizes the doctor.

He says:

> "Doctor."

Pause.

> "...You remember me?"

The game should use the previous interaction.

If the doctor promised something:

Mikhail can reference it.

If the doctor asked about his family:

Mikhail can mention it.

If the doctor treated him with care:

his demeanor can reflect that.

If the doctor was cold:

his interaction can be more guarded.

---

# 43. MIKHAIL'S GIFT

Mikhail may offer a photograph.

Not because the player unlocked:

```text
Friendship Level 2
```

but because a relationship has developed.

The photograph becomes a persistent object.

It may later appear:

* on the doctor's desk
* in inventory
* during family scenes
* in future dialogue

---

# 44. SCENE 6 — FAMILY / ECONOMY

The player returns to their desk.

Another letter or financial update arrives.

Example:

```text
Coal price increased.
```

The player must decide whether to send additional money.

The system records the choice.

---

# 45. SCENE 7 — NIGHT INCIDENT

The hospital becomes quieter.

Sergei experiences a panic episode.

Possible responses:

```text
CALL SECURITY

TALK TO HIM

GIVE MEDICATION

WAIT

GET THE NURSE
```

The available situation and dialogue should depend partially on earlier behavior.

Do not make the player fight a conventional enemy.

The point is judgment under pressure.

---

# 46. FINAL SCENE — DOCTOR'S DESK

The player returns to their room.

On the desk:

* family letter
* money
* medical notes
* Mikhail's photograph
* possibly a medical supply record

The player can write a response to the family.

No narrator explains what happened.

No morality score.

No ending screen saying:

> "You were compassionate."

The game simply leaves the player with the consequences of their actions.

---

# 47. THREE TEST PLAYTHROUGHS

The vertical slice must support at least three broad behavior patterns.

## RUN A

Player frequently:

* helps
* asks questions
* gives scarce medicine
* sends money home
* takes personal risks

## RUN B

Player frequently:

* conserves supplies
* follows rules
* minimizes personal involvement
* makes practical decisions

## RUN C

Player frequently:

* prioritizes self-preservation
* keeps resources
* avoids emotional conversations
* sends less money

The first ~15 minutes should remain mostly similar.

The final ~5–10 minutes should begin to diverge.

Not through massive branching.

Through:

* different dialogue
* different reactions
* different availability
* different remembered details
* different atmosphere
* different small consequences

---

# 48. THE IMPORTANT TEST

The player should be able to finish the slice and answer:

### Question 1

> "Did characters remember what I did?"

### Question 2

> "Did my decisions affect the world?"

### Question 3

> "Did the game understand something about me?"

### Question 4

> "Would I replay this while behaving differently?"

These are more important than raw content quantity.

---

# 49. DATA-DRIVEN ARCHITECTURE

Design the project so content is separate from engine logic.

Suggested structure:

```text
src/
    main
    core/
    game/
    systems/
    ui/
    rendering/
    audio/
    save/
    data/

assets/
    sprites/
    characters/
    environments/
    ui/
    portraits/
    audio/
    fonts/

data/
    patients/
    treatments/
    dialogue/
    events/
    items/
    locations/
    economy/

tests/

docs/
    PROJECT_AUDIT.md
    ART_STYLE.md
    ARCHITECTURE.md
```

Adapt this structure to the existing repository where appropriate.

---

# 50. SYSTEM MODULES

Create or refactor toward modules such as:

```text
GameState
TimeSystem
PlayerState
BehaviorTracker
RelationshipSystem
PatientSystem
TreatmentSystem
InventorySystem
EconomySystem
FamilySystem
DialogueSystem
EventSystem
NarrativeDirector
SaveSystem
UIManager
AudioManager
AssetManager
```

Keep dependencies clear.

Avoid a giant `main.cpp`.

---

# 51. GAME STATE

The central game state should contain or reference:

```text
current day
current time
player money
family state
hospital state
inventory
patients
relationships
behavior history
active events
completed events
world conditions
```

Everything important must be serializable.

---

# 52. SAVE SYSTEM

Implement versioned save data.

Example:

```text
SAVE_VERSION = 1
```

If the data format changes:

* migrate old saves where possible
* fail gracefully where migration is impossible
* never silently corrupt saves

Persist:

* player state
* patients
* patient memories
* behavior events
* relationships
* economy
* family
* world state
* current day
* inventory
* important narrative flags

---

# 53. PATIENT DATA

Patients should be data-driven.

Example conceptual schema:

```text
Patient {
    id
    name
    age
    occupation
    origin
    injuries
    medical_state
    personality_traits
    fears
    family
    memories
    promises
    relationship
    treatment_history
    return_conditions
}
```

Do not hardcode every patient into gameplay logic.

---

# 54. TREATMENT DATA

Treatments should be data-driven.

Example:

```text
Treatment {
    id
    name
    description
    required_inventory
    inventory_cost
    compatible_conditions
    effects
    risks
    patient_reactions
}
```

The actual medical simulation can remain intentionally simplified.

This is a narrative game, not a medical simulator.

---

# 55. DIALOGUE DATA

Dialogue should support:

* speaker
* text
* conditions
* choices
* consequences
* memory references
* behavior evidence
* follow-up events

Example conceptual structure:

```text
DialogueNode {
    id
    speaker
    text
    conditions[]
    choices[]
}
```

---

# 56. CONDITIONAL DIALOGUE

Example:

```text
IF patient remembers promise
THEN use promise dialogue.
```

Example:

```text
IF doctor previously asked about family
THEN patient may reference family.
```

Example:

```text
IF doctor refused medicine
THEN patient may react differently.
```

---

# 57. EVENT SYSTEM

Events should be data-driven.

Example:

```text
Event {
    id
    prerequisites
    probability
    timing
    participants
    actions
    consequences
}
```

Possible events:

```text
FALSE_ALARM
PATIENT_PANIC
SUPPLY_SHORTAGE
FAMILY_LETTER
PRICE_INCREASE
STAFF_ARGUMENT
RETURNING_PATIENT
MILITARY_ORDER
```

---

# 58. RUNTIME ADAPTATION

The game should adapt at runtime.

However:

## DO NOT allow an AI model to rewrite arbitrary executable game code while the game is running.

The deterministic engine must remain in control.

Instead use:

```text
ENGINE
+
DATA
+
RULES
+
AUTHORED CONTENT
```

AI can later assist with generating:

* dialogue
* patient variants
* letters
* rumors
* events
* descriptions
* story connections

but all generated content must be validated before entering the game.

---

# 59. FUTURE AI INTEGRATION

Prepare interfaces for future AI integration.

For example:

```text
NarrativeSuggestion
PatientSuggestion
DialogueSuggestion
EventSuggestion
```

These should be structured objects.

Example:

```text
{
    "type": "dialogue_variant",
    "patient_id": "mikhail",
    "context": "return_visit",
    "conditions": [],
    "text": "...",
    "confidence": 0.8
}
```

The engine validates it.

The engine decides whether it is legal.

The engine applies it.

AI does not control the simulation directly.

---

# 60. JULES DEVELOPMENT BEHAVIOR

Work autonomously.

When you encounter an implementation decision:

### If the decision is minor:

Make the decision and continue.

### If multiple approaches are viable:

Choose the approach that best preserves:

* maintainability
* modularity
* performance
* extensibility
* simplicity

### Only stop for clarification if:

The ambiguity would materially change the game's direction or require destructive architectural changes.

Do not repeatedly ask for permission to perform normal engineering work.

---

# 61. ITERATIVE DEVELOPMENT

Do not attempt to write everything at once.

Use this cycle:

```text
INSPECT
↓
IMPLEMENT
↓
BUILD
↓
RUN
↓
TEST
↓
OBSERVE
↓
FIX
↓
REFACTOR
↓
CONTINUE
```

After significant implementation:

* compile
* run tests
* launch the game
* inspect visual output
* inspect input
* inspect state transitions
* fix issues

Do not assume code works merely because it compiles.

---

# 62. VISUAL QA

When visual verification is possible, inspect:

* alignment
* text readability
* pixel scaling
* UI consistency
* animation
* character placement
* clipping
* incorrect layering
* interaction feedback
* camera transitions

Fix obvious visual defects.

---

# 63. TESTING

Create automated tests where practical.

Especially test:

### Patient memory

```text
interaction
→ save
→ reload
→ memory persists
```

### Treatment

```text
use morphine
→ inventory decreases
→ patient state changes
```

### Behavior

```text
player action
→ behavior event
→ persisted
```

### Dialogue

```text
condition true
→ correct node
```

### Returning patient

```text
patient treated
→ patient leaves
→ patient returns
→ prior memory available
```

### Economy

```text
send money
→ money decreases
→ family state updates
```

### Save/load

```text
save
→ restart
→ load
→ state restored
```

---

# 64. DEBUG TOOLS

Create a development/debug mode.

Useful commands:

```text
give_morphine
set_money
advance_day
trigger_event
spawn_patient
return_patient
show_behavior
show_patient_memory
show_story_state
```

The player should not see these in release builds.

Debugging tools will dramatically speed up development.

---

# 65. DEBUG INFORMATION

Provide optional developer overlays:

```text
Current Day
Current Time
Patient ID
Behavior Events
Active Story Rules
Inventory
Money
Current Event
```

Make them toggleable.

---

# 66. PERFORMANCE

This is a relatively small 2D game.

Prioritize:

* clean architecture
* fast iteration
* reliable state
* deterministic behavior

Do not prematurely optimize.

Avoid unnecessary frameworks.

Raylib should remain the foundation.

---

# 67. AUDIO

Audio should be subtle.

Examples:

* footsteps
* dishes
* distant voices
* wind
* heating pipes
* hospital doors
* paper
* medical tools
* breathing
* distant vehicles
* winter ambience

Important conversations should sometimes reduce ambient sound.

Silence is useful.

---

# 68. MUSIC

Avoid constant music.

Use music selectively.

Possible structure:

```text
Dining Hall:
quiet room ambience

Treatment:
minimal ambience

Personal conversation:
very subtle musical texture

Night:
mostly environmental sound

Major incident:
environmental sound changes first
```

Do not turn every event into cinematic music.

---

# 69. UI PRINCIPLES

The UI should feel like part of the world.

Avoid:

* modern game HUDs
* giant health bars
* XP popups
* floating damage numbers
* excessive icons
* excessive notifications

Prefer:

* paper
* labels
* handwritten notes
* medical forms
* physical objects
* restrained panels
* subtle highlights

---

# 70. CAMERA

Use different camera language for:

### Normal gameplay

Top-down or side-on hospital navigation depending on existing implementation.

### Treatment

Focused patient examination framing.

### Emotional dialogue

Closer character framing.

### Major event

Controlled cinematic framing.

The transition should be seamless.

---

# 71. CHARACTER ANIMATION

Characters should communicate state through:

* posture
* walking
* sitting
* looking
* trembling
* breathing
* turning away
* holding injured limbs
* gestures

Do not rely exclusively on text to communicate emotion.

---

# 72. PATIENT EMOTIONAL STATES

Patients may have states such as:

```text
CALM
PAINFUL
ANXIOUS
AFRAID
HOPEFUL
ANGRY
EXHAUSTED
WITHDRAWN
TRUSTING
DISTRUSTFUL
```

These should influence:

* animation
* dialogue
* response
* treatment presentation

Avoid turning this into visible RPG stats.

---

# 73. RELATIONSHIPS

Relationships should be contextual.

Instead of:

```text
Mikhail relationship = 74
```

store events such as:

```text
Mikhail remembers:
- doctor gave morphine
- doctor asked about mother
- doctor promised follow-up
- doctor remembered name
```

Then derive behavior from those memories.

This creates more believable relationships.

---

# 74. CONSEQUENCE DESIGN

Consequences should usually be:

* delayed
* contextual
* believable
* partial
* reversible where appropriate

Avoid:

```text
Choice A = good ending
Choice B = bad ending
```

Instead:

```text
Choice A changes relationship.
Relationship changes later dialogue.
Dialogue changes a later decision.
That decision changes an event.
```

---

# 75. RANDOMNESS

Randomness should create variation, not erase causality.

Bad:

```text
50% chance anything happens
```

Better:

```text
behavior
+
world state
+
patient state
+
time
+
small randomness
```

The player should feel:

> "That happened because of the world."

Not:

> "The game rolled a dice."

---

# 76. REPLAYABILITY

Replayability should come from:

* different patients
* different conversations
* different supply decisions
* different relationships
* different family outcomes
* different incidents
* different interpretations of the same situations

Not simply procedural randomness.

---

# 77. NO CONTENT BLOAT

Do not create 500 patients before the core loop works.

Do not create huge dialogue databases.

Do not generate hundreds of sprites.

Do not create a giant procedural system before proving the experience.

First make:

```text
1 hospital
2–3 important patients
1 family
1 day
1 major incident
1 returning patient
```

feel excellent.

---

# 78. DEVELOPMENT PHASES

## PHASE 1 — AUDIT

Inspect repository.

Create:

```text
PROJECT_AUDIT.md
```

Run existing project.

---

## PHASE 2 — FOUNDATION

Implement/refactor:

* game state
* scene/state machine
* input
* rendering
* asset loading
* UI foundation
* time
* save/load

---

## PHASE 3 — HOSPITAL

Build:

* dining hall
* corridor
* treatment room
* doctor's desk

---

## PHASE 4 — PATIENT SYSTEM

Implement:

* patient data
* examination
* treatment
* treatment inventory
* patient state
* patient records

---

## PHASE 5 — MEMORY

Implement:

* patient memories
* behavior events
* relationships
* returning patients

---

## PHASE 6 — DIALOGUE

Implement:

* normal dialogue
* cinematic dialogue
* choices
* conditions
* consequences

---

## PHASE 7 — FAMILY / ECONOMY

Implement:

* money
* wages
* food
* family letters
* sending money
* inflation/shortages

---

## PHASE 8 — STORY DIRECTOR

Implement:

* event rules
* behavior interpretation
* event selection
* adaptive dialogue

---

## PHASE 9 — VERTICAL SLICE

Complete:

# THE LAST MEAL

Do not proceed into massive content production until the slice works.

---

# 79. DEFINITION OF DONE FOR THE VERTICAL SLICE

A player must be able to:

1. Enter the dining hall.
2. Receive food.
3. Learn the basic money system naturally.
4. Receive a family letter.
5. Send money.
6. Enter the hospital.
7. Meet Mikhail.
8. Examine Mikhail.
9. Treat Mikhail.
10. Make a meaningful medical/resource decision.
11. Have a personal conversation.
12. Meet Sergei.
13. Make another scarce-resource decision.
14. Walk through ordinary hospital life.
15. Have Mikhail return.
16. See evidence that Mikhail remembers.
17. Receive/see the photograph.
18. Receive another family/economic development.
19. Experience the night incident.
20. Return to the doctor's desk.
21. Save.
22. Reload.
23. Verify memories and state persist.

---

# 80. QUALITY BAR

The vertical slice is NOT complete simply because all mechanics technically exist.

It must feel coherent.

The player should understand:

* where they are
* what their job is
* who these people are
* what matters
* why resources are scarce
* why family matters
* why patient memory matters

without reading a manual.

---

# 81. WHAT NOT TO DO

Do not create:

* morality bars
* XP
* skill trees
* generic quest markers
* giant tutorial popups
* excessive UI
* arbitrary branching for its own sake
* procedural dialogue gibberish
* random consequences unrelated to player behavior
* AI-controlled game logic
* giant inventory spreadsheets
* combat unless later required by the design
* fantasy RPG systems
* modern-looking UI

---

# 82. MOST IMPORTANT DESIGN RULE

If a mechanic makes the player feel like they are manipulating a game system rather than living inside a hospital, reconsider it.

The ideal interaction is:

> "I need to decide what to do."

not:

> "Which option gives the most points?"

---

# 83. THE MEMORY TEST

After the vertical slice is playable, deliberately perform these tests.

### Test A

Give Mikhail morphine.

Ask about his family.

Promise to check his leg.

Have him return.

Verify all three details can influence the return conversation.

### Test B

Refuse morphine.

Be emotionally distant.

Have Mikhail return.

Verify his behavior differs.

### Test C

Give Sergei scarce medicine.

Later create a scarcity condition.

Verify the earlier resource decision affects available resources.

### Test D

Send most money home.

Trigger another family request.

Verify the family state reflects the earlier choice.

### Test E

Save halfway through.

Close the game.

Reload.

Verify persistent memory.

---

# 84. FINAL DESIGN PRINCIPLE

The game should create a strange loop:

```text
PLAYER
   ↓
acts
   ↓
WORLD REMEMBERS
   ↓
PLAYER RETURNS
   ↓
WORLD RESPONDS
   ↓
PLAYER REALIZES
   ↓
"THE GAME REMEMBERED."
```

That feeling is the project's primary goal.

Everything else exists to support it.

---

# 85. FIRST JULES TASK

Begin immediately with the following sequence:

### STEP 1

Inspect the entire repository.

### STEP 2

Run the existing project.

### STEP 3

Create:

`PROJECT_AUDIT.md`

### STEP 4

Create/update:

`AGENTS.md`

with the important architectural and gameplay rules from this document.

### STEP 5

Determine the smallest set of changes required to create the vertical slice.

### STEP 6

Implement the foundation.

### STEP 7

Compile and run.

### STEP 8

Implement the first playable dining hall.

### STEP 9

Implement Mikhail.

### STEP 10

Implement treatment.

### STEP 11

Implement persistent patient memory.

### STEP 12

Implement Sergei.

### STEP 13

Implement family/economy.

### STEP 14

Implement Mikhail's return.

### STEP 15

Implement the night incident.

### STEP 16

Implement save/load.

### STEP 17

Run the complete vertical slice.

### STEP 18

Test the three behavioral playthroughs.

### STEP 19

Fix bugs and visual issues.

### STEP 20

Document what has been implemented and what remains.

---

# 86. JULES WORKING PRINCIPLE

Do not wait for perfect certainty.

Build the smallest convincing version.

Test it.

Improve it.

Keep the architecture flexible.

Prefer working gameplay over speculative infrastructure.

Prefer player experience over technical novelty.

Prefer subtle consequences over obvious branching.

Prefer memory over statistics.

Prefer human reactions over numerical rewards.

And above all:

## Make the hospital remember the player.
