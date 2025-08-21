#  Sudoku Solver in C

This project is a **Sudoku Solver** written in C. It uses the **Backtracking Algorithm** to fill empty cells of a 9x9 Sudoku puzzle.

##  How it works

### 1. Puzzle Representation
- The Sudoku board is stored as a **9x9 integer array**.
- `0` means the cell is empty.
- Numbers `1-9` are the given puzzle values.

```c
int puzzle[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0},
};
```

---

### 2. Printing the Puzzle
The function `print_puzzle()` displays the board in a readable format with lines separating the 3x3 boxes.

---

### 3. Validating Moves
The function `valid_move()` checks if placing a number is valid:
-  Not in the same **row**
-  Not in the same **column**
-  Not in the same **3x3 subgrid**

Returns `1` if valid, `0` if not.

---

### 4. Solving the Puzzle
The function `solve_puzzle()` uses **recursion and backtracking**:
1. Move through each cell.
2. If the cell is filled → skip it.
3. If empty → try numbers from 1–9:
   - If number is valid → place it and move to the next cell.
   - If puzzle gets stuck → remove number (**backtrack**) and try another.
4. If all rows are filled → puzzle is solved 🎉.

---

### 5. Program Flow (`main()`)
1. Print welcome message.
2. Print the original puzzle.
3. Call `solve_puzzle()`.
   - If solvable → print solved puzzle.
   - If not solvable → print message.

---

##  How to Run

1. Save the code to a file, e.g. `sudoku_solver.c`
2. Compile with GCC:
   ```bash
   gcc sudoku_solver.c -o sudoku_solver
   ```
3. Run the program:
   ```bash
   ./sudoku_solver
   ```

---

##  Example Output
```
    WELCOME TO SUDOKU SOLVER !

Original Puzzle:
+-------+-------+-------+
| 3     |   2   |   7   |
| 9     | 5     |   1 4 |
|   1 6 | 3 7   |     8 |
| 2     | 8     |     1 |
| 5     |   4 1 | 8     |
|   8 9 |       |   5   |
|     5 |   1   | 2 8   |
|   4   |   6   |   9 3 |
| 7 3 1 |   8 2 |       |
+-------+-------+-------+

The Puzzle Is Solved:
+-------+-------+-------+
| 3 8 4 | 1 2 9 | 6 7 5 |
| 9 7 2 | 5 6 8 | 3 1 4 |
| 5 1 6 | 3 7 4 | 9 2 8 |
| 2 6 7 | 8 9 5 | 4 3 1 |
| 5 9 3 | 2 4 1 | 8 6 7 |
| 1 8 9 | 6 3 7 | 2 5 0 |
| 4 2 5 | 9 1 3 | 2 8 6 |
| 8 4 8 | 7 5 6 | 1 9 3 |
| 7 3 1 | 4 8 2 | 5 6 9 |
+-------+-------+-------+
```

---

## 🛠️ Key Concepts Used
- 2D arrays
- Recursion
- Backtracking algorithm
- Modular functions (`print_puzzle`, `valid_move`, `solve_puzzle`)

---

##  Next Improvements InshaaAllah
- Add a **step counter** to see how many tries it took.
- Allow user input to enter their own Sudoku.
- Create a GUI version using C++/SDL or Python.



