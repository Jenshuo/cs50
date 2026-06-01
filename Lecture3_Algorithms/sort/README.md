# Sort

CS50x Problem Set 3

## Problem Description

Analyze three pre-compiled sorting programs (`sort1`, `sort2`, `sort3`) and identify which sorting algorithm each one implements: selection sort, bubble sort, or merge sort.

## Background

### Sorting Algorithms

| Algorithm | Description | Best Case | Worst Case |
|-----------|-------------|-----------|------------|
| Selection Sort | Repeatedly finds the minimum element from the unsorted portion and moves it to the front | Ω(n²) | O(n²) |
| Bubble Sort | Repeatedly compares adjacent pairs and swaps them if out of order | Ω(n) | O(n²) |
| Merge Sort | Recursively divides the list in half and merges sorted halves | Ω(n log n) | O(n log n) |

## Testing Method

Run each program against the provided test files using `time` to measure execution:

```
time ./sort1 random10000.txt
time ./sort1 sorted10000.txt
time ./sort1 reversed10000.txt
```

Test files provided:

| File | Description |
|------|-------------|
| `random5000.txt` / `random10000.txt` / `random50000.txt` | Randomly shuffled numbers |
| `sorted5000.txt` / `sorted10000.txt` / `sorted50000.txt` | Already sorted numbers |
| `reversed5000.txt` / `reversed10000.txt` / `reversed50000.txt` | Reverse sorted numbers |

## Results

### sort1 → Bubble Sort

Fastest on already-sorted input (best case Ω(n)), slowest on random input. The performance gap between sorted and unsorted data is the key indicator.

### sort2 → Merge Sort

Consistently fast across all input types (random, sorted, reversed). Merge sort always runs in O(n log n) regardless of input order.

### sort3 → Selection Sort

Slow on both random and sorted input — performance does not improve for already-sorted data. Selection sort always scans the full unsorted portion regardless of order, giving Ω(n²) even in the best case.
