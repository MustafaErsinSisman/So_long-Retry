*This project has been created as part of the 42 curriculum by musisman.*

# Description

**so_long** is a small-scale 2D game project that introduces the fundamentals of basic 2D graphics, texture management, and window event handling. Developed using the **MiniLibX** graphical library, the primary objective of this project is for the player to navigate a maze-like map, collect all scattered items, and ultimately reach the exit door.

# Instructions

### 1. Setup and Compilation

This project is designed to run in a Linux environment. To compile the project, the following components must be ready on your system:

* **Standard Tools:** A C compiler (`gcc` or `cc`) and the `make` utility.
* **X11 Libraries:** System libraries required by MiniLibX to manage windows (`libx11-dev` and `libxext-dev`).
* **MiniLibX:** The graphics library itself is not included in this repository. To compile the project, you must download the MiniLibX library separately and place it in the root directory of the project under the name `minilibx-linux`.

Once the requirements are met, simply navigate to the project directory via the terminal and run the following command to compile the project:
```bash
make
```

### 2. Execution

To launch the game, a valid map file (with a `.ber` extension) must be provided as an argument. Map files can be found in the `maps/` directory.
```bash
./so_long maps/map.ber
```

### 3. Controls and Gameplay

* **W, A, S, D**: Move the character (Up, Left, Down, Right).
* **ESC / Window Cross (X)**: Close the game safely with zero memory leaks.

**Game Rules:**
* The map consists of Walls (`1`), Floor (`0`), Collectibles (`C`), a Player (`P`), and an Exit (`E`).
* **All** items on the map must be collected before the exit door can be opened.
* Once all items are collected, reaching the exit door wins the game.
* The character's current move count is displayed in real-time on the terminal screen.

---

# Resources

### AI Usage
In this project, AI tools were primarily used for conceptual research and finding educational materials. Specifically:
* Researched which pathfinding algorithm should be used to verify map playability, leading to the implementation of the **Flood Fill** algorithm based on AI recommendations.
* Sought guidance from AI to understand the underlying logic of keyboard signals (KeySyms) in the Linux windowing system and to find relevant tutorial videos.

### References & Core Concepts

* **Map Validation (Pathfinding):** [Flood Fill Algorithm for so_long (YouTube)](https://www.youtube.com/watch?v=5Bochyn8MMI)
    * The Flood Fill algorithm was integrated to verify whether all collectibles and the exit door are accessible to the player.
* **MiniLibX & Memory Management:**
    * Handled loading image files into memory and rendering them to the window. Ensured all pointers are properly destroyed in the correct order to achieve zero memory leaks on Valgrind when the game is closed.
