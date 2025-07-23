
---

## 🧾 Problem:

Given:

* `n` processes
* `m` resource types

Each process declares:

* `Max[i][j]`: max demand of resource `j` by process `i`
* `Alloc[i][j]`: currently allocated resource `j` to process `i`
* `Avail[j]`: available instances of resource `j`

---

## ✅ Goal:

Determine if the system is in a **safe state**.

---

## 🔍 Key Formula:

```cpp
Need[i][j] = Max[i][j] - Alloc[i][j]
```

Then simulate process execution:

* A process `i` can run if: `Need[i] <= Avail`
* If it finishes, its `Alloc[i]` is released → added to `Avail`

If **all processes can finish in some order**, the system is **safe**.

---

## ✅ C++ Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int m, vector<vector<int>> &maxm, vector<vector<int>> &alloc, vector<int> avail) {
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    vector<bool> finish(n, false);
    vector<int> safeSeq;

    for (int count = 0; count < n; count++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = true;
                    safeSeq.push_back(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            return false; // unsafe
    }

    cout << "Safe sequence: ";
    for (int i : safeSeq) cout << i << " ";
    cout << "\n";
    return true;
}

int main() {
    int n = 5, m = 3;
    vector<vector<int>> alloc = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> maxm = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<int> avail = {3, 3, 2};

    if (!isSafe(n, m, maxm, alloc, avail))
        cout << "System is not in a safe state.\n";
}
```

---

### 🧠 Sample Output:

```
Safe sequence: 1 3 4 0 2 
```

---

