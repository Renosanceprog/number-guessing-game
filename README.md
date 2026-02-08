# 🔮 The Grand Number Divination Game

**Greetings, seeker of numerical truth!**

Welcome to my digital crystal ball, a console-based challenge written in the arcane runes of **C**. Do you possess the foresight to divine the hidden integer? Or will you stumble in the dark void of probability? Come, test your luck and logic in my domain!

## ✨ Features of the Realm

* **Two Modes of Divination:**
* **🧘 Zen Mode:** A path of relaxed contemplation! Meditate upon the numbers between **1 and 1000** with infinite attempts. There is no failure here, only learning.
* **⚔️ Trial Mode:** A high-stakes gauntlet! You must divine the number before your attempts run dry. Only the worthy shall pass!


* **The Three Tiers of Difficulty (Trial Mode):**
* **🌱 Easy:** 10 attempts to find a number within the **1–100** aether.
* **🔥 Medium:** 5 attempts to pinpoint a number within **1–50**.
* **💀 Hard:** 3 measly attempts to strike true within **1–20**. A true test of valor!


* **The Oracle's Whispers:** The program shall guide you! It will joyously proclaim if your guess is "Too High," "Too Low," or "Correct!"
* **Anti-Chaos Wards (Input Validation):** My spells are robust! If you clumsily type a letter instead of a number, the game shall not crash—it will simply scold you and ask again.

## 📜 Reagents & Requirements

* **Operating Realm:** **Windows** (For I utilize the `system("cls")` incantation to wipe the slate clean).
* **The Catalyst:** **GCC (MinGW)** or any standard C compiler to weave the code into existence.

## ⚗️ How to Transmute Code into Executable

1. **Scribe the Scroll:** Save the code file as `NumberGuesser.c`.
2. **Open the Portal:** Summon your terminal and navigate to the folder where the scroll rests.
3. **Cast the Compilation Spell:**
```bash
gcc NumberGuesser.c -o game

```


4. **Summon the Game:**
```bash
./game

```



## 🎮 Ritual of Play

1. **Begin:** Run the executable to enter my sanctum.
2. **Choose Your Path:**
* Press **A** to enter the **Zen Mode** (The Infinite Path).
* Press **B** to enter the **Trial Mode** (The Gauntlet).


3. **The Divination:**
* Type a number and press **Enter**.
* Heed the wizard's feedback!
* Adjust your mental calculations and guess again!


4. **Fate:**
* **Zen Mode:** The ritual ends only when truth is found.
* **Trial Mode:** Victory is yours if you guess correctly; shame is yours if you run out of tries!


5. **The Cycle Continues:** Type `1` to cast the spell again, or `0` to banish the window.

## 🧩 The Anatomy of the Spell (Code Structure)

* `main()`: The heart of the ritual. It controls the loop of time and menu selection.
* `zen()`: The incantation for the infinite-attempt mode (Range: 1-1000).
* `trial()`: The incantation for the limited-attempt mode with varying difficulty.
* `rng(min, max)`: A chaotic function that consults the spirits of `rand()` and `time()` to pluck a number from the ether.
* `valueinput()` & `modeinput()`: Guardian spells that protect the program from crashing when you input foolish characters.

## 📝 A Note on Inter-Dimensional Compatibility

* **Attention Linux & Mac Sorcerers:** My screen-clearing magic relies on `system("cls")`, a Windows-native chant. To run this in your realms, you must alter the source code: change `system("cls")` to `system("clear")`.

---

**Grand Archmage:** Renosanceprog
**Written in the Tongue of:** C
**Forged in the Year:** 2026
