# Readability

CS50x Problem Set 2

## Problem Description

Implement a program that calculates the approximate U.S. grade level required to comprehend a given text, using the Coleman-Liau readability index.

## Background

The Coleman-Liau index estimates the reading level of a text based on the average number of letters and sentences per 100 words:

```
index = 0.0588 * L - 0.296 * S - 15.8
```

Where:
- **L** = average number of letters per 100 words
- **S** = average number of sentences per 100 words

## Definitions

| Term | Definition |
|------|-----------|
| Letter | Any alphabetic character (`isalpha()`) |
| Word | Any sequence of characters separated by spaces |
| Sentence | Ends with `.`, `!`, or `?` |

## Specification

- Prompt the user for a string of text
- Count the number of letters, words, and sentences
- Compute L and S, then apply the Coleman-Liau formula
- Round the result to the nearest integer and output:
  - `Grade 1` through `Grade 15` for grades 1–15
  - `Grade 16+` for grade 16 and above
  - `Before Grade 1` for grade less than 1

## Examples

```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

```
$ ./readability
Text: It was a bright cold day in April, and the clocks were striking thirteen.
Grade 10
```

```
$ ./readability
Text: A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
Grade 16+
```

## Implementation Notes

- Use `round()` from `math.h` to round the index to the nearest integer
- Cast to `float` before division to avoid integer truncation when computing L and S
- Required headers: `cs50.h`, `ctype.h`, `math.h`, `stdio.h`, `string.h`
