# Caesar

CS50x Problem Set 2

## Problem Description

Implement a program that encrypts text using the Caesar cipher — a simple substitution cipher where each letter is shifted by a fixed number of positions in the alphabet.

## Background

The Caesar cipher shifts each letter by a key `k`. For example, with key `1`, `A` becomes `B`, `B` becomes `C`, and `Z` wraps back to `A`.

The encryption formula is:

```
c = (p + k) % 26
```

Where `p` is the plaintext letter's position (0–25) and `c` is the ciphertext letter's position.

## Specification

- Accept exactly one command-line argument: the encryption key (a non-negative integer)
- If the argument count is wrong or the key contains non-digit characters, print:
  ```
  Usage: ./caesar key
  ```
  and exit with status `1`
- Prompt the user for plaintext with `plaintext: `
- Encrypt each alphabetic character by rotating it `k` positions
- Preserve case — uppercase stays uppercase, lowercase stays lowercase
- Leave non-alphabetic characters (spaces, punctuation, numbers) unchanged
- Output the result as `ciphertext: ` followed by the encrypted text

## Examples

```
$ ./caesar 1
plaintext:  Hello, World!
ciphertext: Ifmmp, Xpsme!
```

```
$ ./caesar 13
plaintext:  Be sure to drink your Ovaltine!
ciphertext: Or fher gb qevax lbhe Binygvar!
```

```
$ ./caesar 27
plaintext:  Hello
ciphertext: Ifmmp
```

```
$ ./caesar
Usage: ./caesar key

$ ./caesar 1 2
Usage: ./caesar key

$ ./caesar abc
Usage: ./caesar key
```

## Implementation Notes

- `only_digits(string s)` — returns `true` if every character in `s` is a digit
- `rotate(char c, int n)` — rotates an alphabetic character by `n` positions, preserving case; returns the character unchanged if non-alphabetic
- Use `atoi()` to convert the key argument from string to integer
- Keys larger than 26 are handled automatically by `% 26`
