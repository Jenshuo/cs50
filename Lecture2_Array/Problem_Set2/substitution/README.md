# Substitution

CS50x Problem Set 2

## Problem Description

Implement a program that encrypts text using a substitution cipher — each letter in the plaintext is replaced by a corresponding letter defined by a 26-character key.

## Background

A substitution cipher maps each letter A–Z to a unique replacement letter. For example, with the key `NQXPOMAFTRHLZGECYJIUWSKDVB`:

```
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
N Q X P O M A F T R H L Z G E C Y J I U W S K D V B
```

So `HELLO` encrypts to `FOLLE`.

## Specification

**Command-line argument:**
- Accept exactly one argument: the encryption key
- If the argument count is wrong, print `Usage: ./substitution key` and exit with status `1`

**Key validation — exit with status `1` if:**
- Key is not exactly 26 characters
- Key contains non-alphabetic characters
- Key contains duplicate letters (each of A–Z must appear exactly once)

**Encryption:**
- Prompt the user with `plaintext: `
- Replace each alphabetic character using the key mapping
- Preserve case — uppercase input → uppercase output, lowercase → lowercase
- Leave non-alphabetic characters unchanged
- Output `ciphertext: ` followed by the encrypted text

## Examples

```
$ ./substitution NQXPOMAFTRHLZGECYJIUWSKDVB
plaintext:  Hello, World!
ciphertext: Folle, Vosld!
```

```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  Meet me on Tuesday evening at seven!
ciphertext: Ybbt yb dn Tdbxpqz bvbning qt xbvbn!
```

```
$ ./substitution
Usage: ./substitution key

$ ./substitution ABC
Key must contain 26 characters.

$ ./substitution NQXPOMAFTRHLZGECYJIUWSKDVV
Key must not contain repeated characters.
```

## Implementation Notes

- Key is case-insensitive — `NQXPOMAFTRHLZGECYJIUWSKDVB` and `nqxpomaftrhlzgecyjiuwskdvb` are equivalent
- Use `toupper()` or `tolower()` to normalize the key before use
- Use `isalpha()` to validate key characters and identify letters in plaintext
- Remember to cast to `(unsigned char)` when calling `ctype.h` functions
