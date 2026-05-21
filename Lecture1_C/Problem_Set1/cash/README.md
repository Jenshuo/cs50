# Cash

CS50x Problem Set 1

## Problem Description

Calculate the minimum number of coins needed to make change using a greedy algorithm.

## Greedy Algorithm

Always use the largest coin possible first: quarters (25¢) → dimes (10¢) → nickels (5¢) → pennies (1¢). This is both locally and globally optimal for U.S. currency.

For example, 41¢:
- 1 quarter → 16¢ remaining
- 1 dime → 6¢ remaining
- 1 nickel → 1¢ remaining
- 1 penny → 0¢ remaining
- **Total: 4 coins**

## Requirements

- Prompt the user for an amount in cents (positive integer)
- Re-prompt if the input is negative
- Print the minimum number of coins

## Usage

```bash
make cash
./cash
```

```
Change owed: 99
9
```

## Implementation

| Function | Description |
|---|---|
| `get_cents()` | Prompts and validates user input (must be >= 0) |
| `calculate_coins(int cents, int unit)` | Returns how many coins of `unit` value fit into `cents` |
| `main()` | Applies greedy algorithm across 25, 10, 5, 1 cent coins and prints total |

## Test Cases

| Input | Expected Output |
|---|---|
| 0 | 0 |
| 1 | 1 |
| 5 | 1 |
| 24 | 6 |
| 25 | 1 |
| 26 | 2 |
| 70 | 4 |
| 99 | 9 |

## Testing

```bash
check50 cs50/problems/2024/x/cash
style50 cash.c
```
