# Tideman

CS50x Problem Set 3

## Problem Description

Implement a program that simulates the Tideman voting method — a ranked-choice system that identifies the Condorcet winner by constructing and locking a directed graph of head-to-head matchups.

## Background

### Condorcet Winner

A candidate who would beat every other candidate in a one-on-one comparison. Plurality voting can fail to elect this candidate; the Tideman method guarantees finding them when one exists.

### Algorithm Overview

1. **Tally** — Count how many voters prefer each candidate over each other
2. **Sort** — Order all pairs by the margin of victory (strongest wins first)
3. **Lock** — Add edges to the graph from strongest to weakest, skipping any edge that would create a cycle

The winner is the candidate with **no incoming edges** — meaning no one beats them.

## Data Structures

```c
// preferences[i][j] = number of voters who prefer candidate i over candidate j
int preferences[MAX][MAX];

// locked[i][j] = true means there is an edge from candidate i to candidate j
bool locked[MAX][MAX];

// Each pair stores the winner and loser indices
typedef struct
{
    int winner;
    int loser;
} pair;
```

## Functions to Implement

### `bool vote(int rank, string name, int ranks[])`
Records a voter's `rank`-th preference. Returns `true` if the candidate name is valid.

### `void record_preferences(int ranks[])`
After all ranks for one voter are collected, updates `preferences[i][j]` for every pair where candidate `i` is ranked above candidate `j`.

### `void add_pairs(void)`
Populates the `pairs[]` array with every matchup where one candidate is strictly preferred. Ties are excluded.

### `void sort_pairs(void)`
Sorts `pairs[]` in descending order by victory margin (i.e. `preferences[winner][loser] - preferences[loser][winner]`).

### `void lock_pairs(void)`
Locks each pair's edge into the graph — strongest first — unless doing so would create a cycle.

### `void print_winner(void)`
Prints the name of the candidate who has no incoming edges in the locked graph.

## Example

```
$ ./tideman Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob

Charlie
```

## Cycle Detection

The key challenge is `lock_pairs`. Before locking an edge `A → B`, check whether `B` can already reach `A` through the existing locked edges. If so, locking `A → B` would create a cycle and the edge must be skipped.
