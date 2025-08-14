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

## ● Algorithm: Breadth-First Search (BFS)

### **Input**
- `Matrix prob` → Initial puzzle configuration  
- `Matrix sol` → Goal puzzle configuration  

### **Output**
- `"Success!"` if goal state is found  
- `"Failed!"` if no solution exists  

### **Pseudocode**
```
FUNCTION genmove(state):
    nextStates ← empty list
    FIND coordinates (a, b) where state[a][b] = 0

    IF a > 0:
        s ← copy of state
        swap s[a][b] with s[a-1][b]
        append s to nextStates

    IF a < 2:
        s ← copy of state
        swap s[a][b] with s[a+1][b]
        append s to nextStates

    IF b > 0:
        s ← copy of state
        swap s[a][b] with s[a][b-1]
        append s to nextStates

    IF b < 2:
        s ← copy of state
        swap s[a][b] with s[a][b+1]
        append s to nextStates

    RETURN nextStates
```

```
FUNCTION matrixToString(mat):
    s ← empty string
    FOR each row in mat:
        FOR each value in row:
            append value to s as a string
    RETURN s
```

```
FUNCTION bfs(prob, sol):
    q ← empty queue
    closed ← empty set

    ENQUEUE prob into q
    INSERT matrixToString(prob) into closed

    WHILE q is not empty:
        A ← DEQUEUE from q

        IF A equals sol:
            PRINT "Success!"
            RETURN

        states ← genmove(A)
        FOR each state in states:
            str ← matrixToString(state)
            IF str not in closed:
                INSERT str into closed
                ENQUEUE state into q

    PRINT "Failed!"
```

```
MAIN:
    prob ← [[1, 2, 3],
            [4, 0, 6],
            [7, 5, 8]]

    sol  ← [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 0]]

    CALL bfs(prob, sol)
```

---

## ● Algorithm: Depth-First Search (DFS)

### **Input**
- `Matrix prob` → Initial puzzle configuration  
- `Matrix sol` → Goal puzzle configuration  

### **Output**
- `"Success!"` if goal state is found  
- `"Failed!"` if no solution exists  

### **Pseudocode**
```
FUNCTION dfs(prob, sol):
    s ← empty stack
    closed ← empty set

    PUSH prob into s
    INSERT matrixToString(prob) into closed

    WHILE s is not empty:
        A ← POP from s

        IF A equals sol:
            PRINT "Success!"
            RETURN

        states ← genmove(A)
        FOR each state in states:
            str ← matrixToString(state)
            IF str not in closed:
                INSERT str into closed
                PUSH state into s

    PRINT "Failed!"
```

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
```
Success!
```

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


