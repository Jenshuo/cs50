# Tideman — Solution

## 架構圖

```
main()
 ├── 輸入階段
 │    ├── vote()              將候選人名稱轉換為索引，存入 ranks[]
 │    └── record_preferences() 根據 ranks[] 更新 preferences[][] 矩陣
 │
 └── 計算階段
      ├── add_pairs()         從 preferences[][] 找出所有勝負對，存入 pairs[]
      ├── sort_pairs()        對 pairs[] 依勝票數做 Selection Sort（由大到小）
      ├── lock_pairs()        從最強的對開始鎖定有向邊，跳過會形成 cycle 的邊
      │    └── has_circle()   DFS 遞迴：檢查圖中是否存在從 start 到 target 的路徑
      └── print_winner()      找出 locked[][] 中沒有任何入邊的候選人
```

---

## 資料結構

### `preferences[i][j]`

二維整數矩陣，`preferences[i][j]` 代表「有幾位選民偏好候選人 i 勝過候選人 j」。每位選民投票後由 `record_preferences()` 累加。

### `locked[i][j]`

二維布林矩陣，代表有向圖的鄰接矩陣。`locked[i][j] = true` 表示圖中存在 i → j 的邊，意即 i 打敗 j 且此結果被鎖定。

### `pairs[]`

儲存所有有勝負（非平局）的候選人對，每個 `pair` 包含 `winner` 和 `loser` 的索引。最多 `MAX*(MAX-1)/2` 組。

### `ranks[]`

每位選民投票時的暫存陣列，`ranks[j]` = 選民第 j 順位選擇的候選人索引。

---

## 各函式思路

### `vote(rank, name, ranks[])`

線性搜尋 `candidates[]`，找到與 `name` 相符的候選人後，將其索引記錄在 `ranks[rank]`。找不到則回傳 `false`（無效票）。

### `record_preferences(ranks[])`

雙層迴圈：外層 `i` 從 0 到 `candidate_count - 1`，內層 `j` 從 `i+1` 到 `candidate_count - 1`。因為 `ranks[i]` 排在 `ranks[j]` 前面，所以選民偏好 `ranks[i]` 勝過 `ranks[j]`，對應的 `preferences[ranks[i]][ranks[j]]` 加一。

```
ranks = [2, 0, 1]  (第1志願: 候選人2, 第2志願: 候選人0, 第3志願: 候選人1)
→ preferences[2][0]++  (2 > 0)
→ preferences[2][1]++  (2 > 1)
→ preferences[0][1]++  (0 > 1)
```

### `add_pairs()`

遍歷所有候選人對 (i, j)，若 `preferences[i][j] > preferences[j][i]` 代表 i 在這場對決中獲勝，加入 `pairs[]`。平局（兩邊相等）不加入。

### `sort_pairs()`

使用 **Selection Sort**，依 `preferences[winner][loser]`（勝方獲得的票數）由大到小排列 `pairs[]`。

每輪從未排序的部分找出票數最大的 pair，與當前位置交換。

```
每輪：在 pairs[i..pair_count-1] 中找最大值的索引 max_idx
      若 max_idx != i，則交換 pairs[i] 和 pairs[max_idx]
```

### `lock_pairs()` + `has_circle()`

這是 Tideman 的核心。從最強的 pair 開始，依序嘗試鎖定 `winner → loser` 的有向邊。

鎖定前先呼叫 `has_circle(loser, winner)`，檢查在現有圖中是否已有一條從 `loser` 走到 `winner` 的路徑。若有，鎖定這條邊就會形成 cycle，因此跳過。

`has_circle(start, target)` 使用遞迴 DFS：

```
has_circle(start, target):
  若 start == target → 找到路徑，回傳 true
  對每個候選人 i：
    若 locked[start][i] == true（start 有邊指向 i）：
      遞迴呼叫 has_circle(i, target)
      若回傳 true → 回傳 true
  回傳 false（找不到路徑）
```

### `print_winner()`

掃描每位候選人 i，檢查是否存在任何 j 使得 `locked[j][i] = true`（即有入邊指向 i）。若完整遍歷所有 j 都沒有入邊，則 i 是圖的 source，即勝者，印出其名稱。

---

## 完整流程範例

假設有 Alice (0)、Bob (1)、Charlie (2)，5 位選民：

**投票結果：**
- 3 人偏好 Alice > Bob > Charlie
- 2 人偏好 Bob > Charlie > Alice

**preferences 矩陣：**
```
        Alice  Bob  Charlie
Alice  [  0     3     3   ]
Bob    [  2     0     5   ]
Charlie[  2     0     0   ]
```

**add_pairs：**
```
Alice > Bob    (3 vs 2) → pair(0,1)
Alice > Charlie (3 vs 2) → pair(0,2)
Bob > Charlie  (5 vs 0) → pair(1,2)
```

**sort_pairs（依勝票數排序）：**
```
Bob > Charlie  (5票)  ← 最強
Alice > Bob    (3票)
Alice > Charlie (3票)
```

**lock_pairs：**
```
鎖定 Bob → Charlie    (無 cycle)
鎖定 Alice → Bob      (無 cycle)
鎖定 Alice → Charlie  (無 cycle)
```

**print_winner：**
```
Alice 沒有任何入邊 → 勝者：Alice
```
