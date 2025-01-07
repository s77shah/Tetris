# Tetris Game Project

This repository contains a Tetris game implemented in **C++** using the **SDL2** library for graphics and input handling. The game showcases the core mechanics of Tetris, including piece rotation, line clearing, and collision detection. Below, you'll find an overview of how the code is structured and what each part does.

---

## Features

- **Classic Tetris Mechanics**: Includes block movement, rotation, and line-clearing logic.
- **Matrix-based Design**: The game board and Tetris pieces are stored and managed using matrices, enabling easy manipulation and collision detection.
- **Piece Rotation**: Each piece is pre-defined with its four possible rotations, avoiding complex mathematical calculations during gameplay.
- **Customizable Board**: Board dimensions, block sizes, and other gameplay aspects can be easily modified in the code.
- **Efficient Rendering**: Uses SDL2 for drawing rectangles to represent game pieces and board elements.

---

## How the Code Works

### **1. Pieces**
The `Pieces` class defines all seven Tetris pieces and their rotations using a **4D array**. Each piece is represented as a 5x5 matrix of integers:
- `0`: No block.
- `1`: Regular block.
- `2`: Pivot block (used for rotation).

Example of the "T" piece:
```text
{0, 0, 0, 0, 0},
{0, 0, 1, 0, 0},
{0, 1, 2, 1, 0},
{0, 0, 1, 0, 0},
{0, 0, 0, 0, 0}
```
This setup allows the game to easily handle rotations by switching to the next pre-defined matrix for the piece.

---

### **2. Board**
The `Board` class manages the game grid where pieces fall. It uses a 2D array to track whether each position is filled (`POS_FILLED`) or empty (`POS_FREE`). Key functions include:
- **Collision Detection**: Checks if a piece can move or rotate without colliding with the board's edges or other pieces.
- **Line Clearing**: Detects and removes full lines, shifting blocks above downward.
- **Game Over Check**: Determines if blocks have reached the top of the board.

---

### **3. Game Logic**
The `Game` class controls the overall gameplay, including:
- **Piece Creation**: Generates random pieces and places them at the top of the board.
- **Input Handling**: Processes player inputs for moving, rotating, and dropping pieces.
- **Automatic Falling**: Moves pieces down periodically, checking for collisions and storing pieces when they land.

---

### **4. Rendering and Input**
The `IO` class uses SDL2 to:
- Render blocks as rectangles.
- Clear and update the screen.
- Process keyboard input for controlling the game.

---

## Building and Running

1. Install the SDL2 and SDL2_gfx libraries:
   ```bash
   brew install sdl2 sdl2_gfx   # macOS
   sudo apt-get install libsdl2-dev libsdl2-gfx-dev   # Linux
   ```
2. Clone the repository:
   ```bash
   git clone <repository_url>
   cd tetris_project
   ```
3. Compile the project:
   ```bash
   g++ -std=c++17 -I<SDL2_include_path> -L<SDL2_library_path> -lSDL2 -lSDL2_gfx -o tetris Main.cpp Board.cpp Game.cpp IO.cpp Pieces.cpp
   ```
4. Run the game:
   ```bash
   ./tetris
   ```

---

## Learning Goals

This project demonstrates:
1. **Matrix Operations**: Using matrices to represent game elements, inspired by the linear algebra concepts I studied in my first semester.
2. **Collision Detection**: Ensuring smooth gameplay by preventing invalid movements.
3. **Game Loop Design**: Implementing an efficient loop for rendering, input processing, and logic updates.

---

## Acknowledgments

- **SDL2 Library**: Provides cross-platform tools for rendering and input.
- **Javier López López's Tetris Tutorial**: This project is based on Javier's excellent guide, with significant extensions and customizations to the codebase.

