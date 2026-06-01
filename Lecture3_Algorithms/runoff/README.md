# Runoff

CS50x Problem Set 3

## Problem Description

Implement a program that simulates a ranked-choice (instant runoff) election. Voters rank candidates by preference, and if no candidate wins a majority, the weakest candidate is eliminated in rounds until a winner emerges.

## Background

In a plurality election, a candidate can win with far less than a majority. Ranked-choice voting fixes this: each voter ranks all candidates in order of preference. If no candidate has more than 50% of first-choice votes, the candidate with the fewest votes is eliminated, and their votes transfer to those voters' next preference. This repeats until one candidate holds a majority.

## Data Structures

```c
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// preferences[i][j] = j-th preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];
```

- `MAX_VOTERS` = 100
- `MAX_CANDIDATES` = 9

## Functions to Implement

### `bool vote(int voter, int rank, string name)`
- Records `name` as the `rank`-th preference for `voter`
- Returns `true` if the candidate exists, `false` otherwise

### `void tabulate(void)`
- Updates each candidate's vote count based on voters' top non-eliminated preference

### `bool print_winner(void)`
- If any candidate has more than 50% of votes, prints their name and returns `true`
- Otherwise returns `false`

### `int find_min(void)`
- Returns the minimum vote total among non-eliminated candidates

### `bool is_tie(int min)`
- Returns `true` if all remaining candidates have the same vote count (i.e. a tie)

### `void eliminate(int min)`
- Eliminates all non-eliminated candidates with exactly `min` votes

## Election Flow

```
1. Collect ranked votes from all voters
2. Tabulate first-choice votes
3. If a candidate has majority → print winner and stop
4. If all remaining candidates are tied → print all and stop
5. Eliminate candidate(s) with fewest votes
6. Repeat from step 2
```

## Example

```
$ ./runoff Alice Bob Charlie
Number of voters: 5
Rank 1: Alice
Rank 2: Bob
Rank 3: Charlie

Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob

Rank 1: Bob
Rank 2: Charlie
Rank 3: Alice

Rank 1: Bob
Rank 2: Alice
Rank 3: Charlie

Rank 1: Charlie
Rank 2: Alice
Rank 2: Bob

Alice
```
