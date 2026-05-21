# Mario (Less Comfortable)

CS50x Problem Set 1

## Problem Description

Recreate the right-aligned pyramid from Super Mario Bros. using hash symbols (`#`).

## Example

For height `3`:

```
  #
 ##
###
```

## Requirements

- Prompt the user for a pyramid height (positive integer)
- Re-prompt if the input is invalid (non-integer, zero, or negative)
- Print a right-aligned pyramid of the given height

## Usage

```bash
make mario
./mario
```

```
Height: 4
   #
  ##
 ###
####
```

## Implementation

| Function | Description |
|---|---|
| `main()` | Gets height input with validation, iterates over each row |
| `print_raw(int space, int brick)` | Prints a single row with the correct number of spaces and `#` |

## Testing

```bash
check50 cs50/problems/2024/x/mario/less
style50 mario.c
```
