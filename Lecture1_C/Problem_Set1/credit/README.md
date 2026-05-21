# Credit

CS50x Problem Set 1

## Problem Description

Validate a credit card number using Luhn's algorithm and identify the card type.

## Luhn's Algorithm

1. Take every other digit starting from the **second-to-last**, multiply each by 2, then sum all the resulting digits
2. Add that to the sum of the digits that were **not** multiplied
3. If the total's last digit is **0**, the number is valid

Example for `4003600000000014`:
- Odd-position digits (×2): 0×2, 0×2, 0×2, 0×2, 6×2=12→1+2, 0×2, 4×2=8 → sum = 20
- Even-position digits: 4+0+0+0+0+0+3+0+4 = 11  (but 1 at the end)
- Total = 20 + 10 = 10 → last digit is 0 → **VALID**

## Card Type Rules

| Type | Length | Starting Digits |
|---|---|---|
| AMEX | 15 | 34, 37 |
| MASTERCARD | 16 | 51–55 |
| VISA | 13 or 16 | 4 |

## Requirements

- Prompt the user for a card number
- Re-prompt if input is invalid (non-numeric)
- Output exactly `AMEX`, `MASTERCARD`, `VISA`, or `INVALID`

## Usage

```bash
make credit
./credit
```

```
Number: 4003600000000014
VISA
```

## Implementation

| Component | Description |
|---|---|
| `CardInfo` (struct) | Stores `luhn_sum`, `digit_count`, `start_two_digit`, `start_one_digit` |
| `luhn_algo(long)` | Iterates digits right-to-left, applies Luhn's algorithm, and captures card metadata |
| `main()` | Calls `luhn_algo()`, checks validity and card type, prints result |

## Test Cases

| Input | Expected Output |
|---|---|
| `378282246310005` | `AMEX` |
| `5105105105105100` | `MASTERCARD` |
| `4003600000000014` | `VISA` |
| `1234567890` | `INVALID` |

## Testing

```bash
check50 cs50/problems/2024/x/credit
style50 credit.c
```
