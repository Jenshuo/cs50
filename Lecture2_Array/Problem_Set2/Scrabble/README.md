# Scrabble

CS50x Problem Set 2

## Problem Description

Implement a program that determines the winner of a Scrabble-like game. Two players each input a word, and the player whose word scores more points wins.

## Background

In Scrabble, players score points by creating words where each letter has a designated point value:

| Points | Letters |
|--------|---------|
| 1  | A, E, I, O, U, L, N, S, T, R |
| 2  | D, G |
| 3  | B, C, M, P |
| 4  | F, H, V, W, Y |
| 5  | K |
| 8  | J, X |
| 10 | Q, Z |

Non-alphabetic characters (punctuation, spaces, etc.) contribute zero points.

## Specification

- Prompt Player 1 and Player 2 each for a word
- Compute each word's score by summing the point values of its letters
- Scoring is case-insensitive (`A` and `a` are worth the same)
- Print `Player 1 wins!`, `Player 2 wins!`, or `Tie!`

## Examples

```
$ ./scrabble
Player 1: red
Player 2: wheelbarrow
Player 2 wins!
```

```
$ ./scrabble
Player 1: COMPUTER
Player 2: science
Player 1 wins!
```

```
$ ./scrabble
Player 1: Question?
Player 2: Question!
Tie!
```

## Implementation

- `POINTS[26]` — maps each letter A–Z to its point value
- `compute_score(string)` — iterates through a word, converts each character to uppercase via `toupper((unsigned char) c)`, and sums the corresponding point values
