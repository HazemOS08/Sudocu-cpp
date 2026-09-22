# C++ Sudoku Game

A simple 9x9 Sudoku game played directly in the terminal.

## How the Game Works
* Rules follow standard Sudoku: numbers 1–9 per row, column, and 3x3 block without repeating.
* The game places a few starting numbers for you when you launch it.
* You get **3 tries** before game over.

## Limitations & Future Improvements

* **Manual Board Input:** Players enter `Row`, `Column`, and `Value` one by one by typing numbers instead of moving with keyboard arrow keys.
* **Random Setup vs. Solvable Puzzles:** Starting numbers are placed completely at random rather than pulled from a pre-made, guaranteed-solvable Sudoku puzzle layout.
* **Fixed 9x9 Size:** Grid sizing and submatrix dimensions are hardcoded for standard 9x9 boards.
* **Basic Error Recovery:** Invalid text or letter inputs in the console prompt can disrupt the menu loop.
