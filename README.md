<h1 align="center">Artificial Intelligence</h1>

## Practical :- 8-Puzzle Problem using BFS and DFS in C++

### ● Problem Statement

The **8-Puzzle Problem** is a classic problem in artificial intelligence and graph theory. It consists of a 3x3 grid with tiles numbered 1-8 and one empty space (represented as `0`). The goal is to move the tiles into the correct position by sliding them one at a time into the empty space, ultimately reaching a predefined goal state.


---

### ● Data Structures Used

| Component         | Data Structure            | Purpose                                          |
|-------------------|---------------------------|--------------------------------------------------|
| Puzzle State      | `vector<vector<int>>`     | 3x3 matrix to represent the puzzle.              |
| Visited Set       | `unordered_set<string>`   | Stores string representations of visited states. |
| Frontier (BFS)    | `queue<Matrix>`           | Stores states to explore next in BFS.            |
| Frontier (DFS)    | `stack<Matrix>`           | Stores states to explore next in DFS.            |
| State Generation  | `list<Matrix>`            | Stores all valid next states.                    |

---

### ● Algorithm: Breadth-First Search (BFS) for 8-Puzzle Problem

#### **Input**
- `Matrix prob` → Initial puzzle configuration (`vector<vector<int>>`)
- `Matrix sol` → Goal puzzle configuration (`vector<vector<int>>`)

#### **Output**
- `"Success!"` if goal state is found
- `"Failed!"` if no solution exists

---

#### **Step 1 – Initialize**
1. Create a queue `q` to store puzzle states for exploration.  
2. Create an unordered set `closed` to store visited states in string form. 
3. Push the initial state `prob` into `q`.  
4. Convert `prob` into a string using `matrixToString` and insert into `closed`.

---

#### **Step 2 – BFS Loop**
While `q` is **not empty**:  
1. Remove the front state `A` from `q`.  
2. **Goal Test:**  
   - If `A` equals `sol`, print `"Success!"` and stop.  
3. **Generate Moves:**  
   - Find the position `(a, b)` of the blank tile (`0`).  
   - Create new states by swapping the blank tile with:
     - **Up** if `a > 0`  
     - **Down** if `a < 2`  
     - **Left** if `b > 0`  
     - **Right** if `b < 2`  
4. For each generated state:
   - Convert the state to a string using `matrixToString`.  
   - If not present in `closed`:
     - Insert it into `closed`.  
     - Push it into `q`.

---

#### **Step 3 – Failure Case**
If the queue becomes empty before finding the goal:  
- Print `"Failed!"`.


### ● Algorithm: Depth-First Search (DFS) for 8-Puzzle Problem

#### **Input**
- `Matrix prob` → Initial puzzle configuration (`vector<vector<int>>`)
- `Matrix sol` → Goal puzzle configuration (`vector<vector<int>>`)

#### **Output**
- `"Success!"` if goal state is found
- `"Failed!"` if no solution exists


#### **Step 1 – Initialize**
1. Create a stack `s` to store puzzle states for exploration.  
2. Create an unordered set `closed` to store visited states in string form.  
3. Push the initial state `prob` into `s`.  
4. Convert `prob` into a string using `matrixToString` and insert into `closed`.



#### **Step 2 – DFS Loop**
While `s` is **not empty**:  
1. Remove the top state `A` from `s`.  
2. **Goal Test:**  
   - If `A` equals `sol`, print `"Success!"` and stop.  
3. **Generate Moves:**  
   - Find the position `(a, b)` of the blank tile (`0`).  
   - Create new states by swapping the blank tile with:
     - **Up** if `a > 0`  
     - **Down** if `a < 2`  
     - **Left** if `b > 0`  
     - **Right** if `b < 2`  
4. For each generated state:
   - Convert the state to a string using `matrixToString`.  
   - If not present in `closed`:
     - Insert it into `closed`.  
     - Push it into `s`.


#### **Step 3 – Failure Case**
If the stack becomes empty before finding the goal:  
- Print `"Failed!"`.


---

### ● Sample Test Cases
#### BFS:
**Initial (Start) State:**

```
1 2 3
4 0 6
7 5 8
```

**Goal (Solution) State:**

```
1 2 3
4 5 6
7 8 0

```
**Output:**
Success!

#### DFS:
**Initial (Start) State:**

```
1 2 3
4 5 6
0 7 8
```

**Goal (Solution) State:**

```
1 2 3
4 5 6
7 8 0
```
**Output:**
```
Success!
```

### ● Use Cases

- **AI Research & Teaching**: Introduces concepts of uninformed search, state space, and heuristics.
- **Pathfinding**: Demonstrates basic BFS and DFS applications in graph traversal.
- **Game Solvers**: Foundation for solving board-based problems (Sudoku, Rubik’s cube).
- **Interview Preparation**: Common example in system design and AI interviews.

---

### ● Files

| Filename                 | Description                                  |
|--------------------------|----------------------------------------------|
| `8_PUZZLE_BFS.cpp`       | BFS-based 8-puzzle solver                    |
| `8_PUZZLE_DFS.cpp`       | DFS-based 8-puzzle solver                    |
| `README.md`              | Explanation and documentation                |


