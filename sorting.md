---

### 🔹 1. **Bubble Sort**

* **Idea**: Repeatedly swap **adjacent** elements if they are in wrong order.
* **Best/Average/Worst Time**:

  * Best: O(n) (if already sorted)
  * Avg/Worst: O(n²)
* **Stable**: ✅
* **Use When**: Almost never (just for learning; it's the slowest).

**Example**:

```
[5, 3, 1] → compare 5 & 3 → swap  
[3, 5, 1] → compare 5 & 1 → swap  
[3, 1, 5] → ...
```

---

### 🔹 2. **Selection Sort**

* **Idea**: Select the **minimum** (or maximum) and put it at correct place.
* **Best/Average/Worst Time**: Always O(n²)
* **Stable**: ❌ (can be made stable but not by default)
* **Use When**: Memory write is costly (min swaps: O(n))

**Example**:

```
Find min in [5, 3, 1] → 1 → swap with 5  
[1, 3, 5]
```

---

### 🔹 3. **Insertion Sort**

* **Idea**: Insert each element into its correct place in the sorted part of array.
* **Best Time**: O(n) (already sorted)
* **Avg/Worst**: O(n²)
* **Stable**: ✅
* **Use When**: Small arrays or nearly sorted

**Example**:

```
[5, 3, 1] → insert 3 before 5 → [3, 5]  
→ insert 1 before 3 → [1, 3, 5]
```

---

### 🔹 4. **Quick Sort**

* **Idea**: Choose a pivot, **partition** array into less/greater, sort recursively.
* **Best/Average Time**: O(n log n)
* **Worst Time**: O(n²) (when badly balanced)
* **Stable**: ❌
* **Use When**: Large datasets, general-purpose (very fast in practice)

**Example**:

```
Pivot = 3  
[5, 3, 1] → split → [1] [3] [5]  
→ recurse on [1] and [5]
```

---

### ⚡ TL;DR Table

| Sort      | Time Avg   | Stable | Idea                        | Use When                   |
| --------- | ---------- | ------ | --------------------------- | -------------------------- |
| Bubble    | O(n²)      | ✅      | Swap adjacent if needed     | Never (learning only)      |
| Selection | O(n²)      | ❌      | Select min & place          | Few swaps are desired      |
| Insertion | O(n²)      | ✅      | Insert into sorted portion  | Small/nearly sorted arrays |
| Quick     | O(n log n) | ❌      | Divide by pivot (partition) | Large datasets (very fast) |

---

### ✅ What is a **Stable Sort**?

A **stable sorting algorithm** maintains the **relative order** of equal elements.

#### Example:

Suppose you have:

```cpp
[ {name: "a", val: 5}, {name: "b", val: 5}, {name: "c", val: 3} ]
```

After stable sort by `val`, you should get:

```cpp
[ {c,3}, {a,5}, {b,5} ]  ✅ (a before b is preserved)
```

If it becomes `[ {c,3}, {b,5}, {a,5} ]` → that's **not stable** ❌

---

### 🔹 Bubble Sort (Stable)

```cpp
void bubble(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
}
```

---

### 🔹 Selection Sort (Not Stable)

```cpp
void selection(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        int mi = i;
        for (int j = i+1; j < n; j++)
            if (a[j] < a[mi]) mi = j;
        swap(a[i], a[mi]);
    }
}
```

---

### 🔹 Insertion Sort (Stable)

```cpp
void insertion(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int x = a[i], j = i-1;
        while (j >= 0 && a[j] > x)
            a[j+1] = a[j--];
        a[j+1] = x;
    }
}
```

---

### 🔹 Quick Sort (Not Stable)

```cpp
int part(vector<int>& a, int l, int r) {
    int p = a[r], i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] < p)
            swap(a[++i], a[j]);
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quick(vector<int>& a, int l, int r) {
    if (l < r) {
        int pi = part(a, l, r);
        quick(a, l, pi - 1);
        quick(a, pi + 1, r);
    }
}
```

To call:

```cpp
quick(arr, 0, arr.size() - 1);
```

---

---

### ✅ 1. **Counting Sort**

* **Idea**: Count occurrences of each value and rebuild the array.
* **Time**: O(n + k), where k = range of input values.
* **Stable**: ✅ (if written carefully)
* **Use When**: Elements are **non-negative integers** in a **small range**.

#### 🔹 Code:

```cpp
void countSort(vector<int>& a) {
    int mx = *max_element(a.begin(), a.end());
    vector<int> cnt(mx + 1, 0);

    for (int x : a) cnt[x]++;
    int idx = 0;
    for (int i = 0; i <= mx; i++)
        while (cnt[i]--) a[idx++] = i;
}
```

---

### ✅ 2. **Shell Sort**

* **Idea**: A variation of insertion sort using **gap-based** comparison.
* **Time**: O(n log² n) worst (depends on gap sequence).
* **Stable**: ❌
* **Use When**: Moderate data size; better than insertion/bubble.

#### 🔹 Code:

```cpp
void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int tmp = a[i], j = i;
            while (j >= gap && a[j - gap] > tmp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tmp;
        }
    }
}
```

---

### ⚡ Final Quick Comparison Table:

| Sort        | Time Avg    | Stable | Extra Space | Best Use Case                           |
| ----------- | ----------- | ------ | ----------- | --------------------------------------- |
| Bubble Sort | O(n²)       | ✅      | O(1)        | Educational, small datasets             |
| Selection   | O(n²)       | ❌      | O(1)        | When swap count must be minimal         |
| Insertion   | O(n²)       | ✅      | O(1)        | Nearly sorted or small arrays           |
| Quick Sort  | O(n log n)  | ❌      | O(log n)    | Large general-purpose sorting           |
| Count Sort  | O(n + k)    | ✅      | O(k)        | Integers in limited value range         |
| Shell Sort  | O(n log² n) | ❌      | O(1)        | Faster than insertion for medium arrays |

---
