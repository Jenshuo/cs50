# Mario (More Comfortable)

CS50x Problem Set 1

## Problem Description

Recreate the adjacent double pyramid from Super Mario Bros. using hash symbols (`#`), with a two-space gap between them.

## Example

For height `4`:

```
   #  #
  ##  ##
 ###  ###
####  ####
```

## Requirements

- Prompt the user for a pyramid height between 1 and 8 (inclusive)
- Re-prompt if the input is invalid (non-integer, zero, negative, or above 8)
- Print two right-and-left aligned pyramids separated by a two-space gap

## Usage

```bash
make mario
./mario
```

```
Height: 3
  #  #
 ##  ##
###  ###
```

## Implementation

| Function | Description |
|---|---|
| `main()` | Gets height input with validation, iterates over each row |
| `print_raw(int num, char symbol)` | Prints `num` repetitions of `symbol` |

Each row prints: spaces → left bricks → two-space gap → right bricks → newline.

## Testing

```bash
check50 cs50/problems/2024/x/mario/more
style50 mario.c
```
