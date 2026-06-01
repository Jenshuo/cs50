# Plurality

CS50x Problem Set 3

## Problem Description

Implement a program that simulates a plurality vote election. Each voter casts one vote for a candidate, and the candidate with the most votes wins. In case of a tie, all tied candidates are printed.

## Background

In a plurality voting system, every voter votes for one candidate. The candidate with the greatest number of votes at the end is declared the winner — no majority required.

## Specification

- Candidates are passed as command-line arguments (maximum 9)
- Prompt for the number of voters, then collect each vote
- If a vote is cast for an invalid candidate, print `Invalid vote.`
- After all votes are counted, print the winner(s) — one name per line
- If multiple candidates tie, print all of them

## Data Structure

```c
typedef struct
{
    string name;
    int votes;
} candidate;
```

## Functions to Implement

### `bool vote(string name)`
- Iterates through the candidates array
- If a match is found, increments that candidate's vote count and returns `true`
- Returns `false` if no candidate matches the name

### `void print_winner(void)`
- Finds the maximum vote count across all candidates
- Prints the name of every candidate with that vote count

## Examples

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```

```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: invalid
Invalid vote.
Alice
Bob
```
