---

### ✅ **Quick Sort Code (In-place, Not Stable)**

```cpp
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r) {
    int pivot = v[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        if(v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return i + 1;
}

void quick_sort(vector<int> &v, int l, int r) {
    if(l < r) {
        int pi = partition(v, l, r);
        quick_sort(v, l, pi - 1);
        quick_sort(v, pi + 1, r);
    }
}

int main() {
    vector<int> v = {10, 7, 8, 9, 1, 5};
    quick_sort(v, 0, v.size() - 1);

    for(int x : v) cout << x << " ";
    return 0;
}
```

---

### 🧠 **Time Complexity**

* Best / Average: `O(n log n)`
* Worst (when already sorted and bad pivot chosen): `O(n²)`
* In-place: ✅
* Stable: ❌

---

### ✅ **Stable & In-place**

| Algorithm          | Stable | In-place | Time Complexity              |
| ------------------ | ------ | -------- | ---------------------------- |
| **Insertion Sort** | ✅ Yes  | ✅ Yes    | Best: O(n), Avg/Worst: O(n²) |
| **Bubble Sort**    | ✅ Yes  | ✅ Yes    | O(n²)                        |
| **Selection Sort** | ❌ No   | ✅ Yes    | O(n²)                        |
| **Merge Sort**     | ✅ Yes  | ❌ No¹    | O(n log n)                   |

¹Merge Sort is *not in-place* in its standard implementation. It can be made in-place, but with added complexity and slower performance.

---

### 🚫 **Not In-place or Not Stable**

| Algorithm         | Stable | In-place | Notes                     |
| ----------------- | ------ | -------- | ------------------------- |
| **Quick Sort**    | ❌ No   | ✅ Yes    | Not stable by default     |
| **Heap Sort**     | ❌ No   | ✅ Yes    | Not stable                |
| **Counting Sort** | ✅ Yes  | ❌ No     | Needs extra space         |
| **Radix Sort**    | ✅ Yes  | ❌ No     | Needs extra space         |
| **Bucket Sort**   | ✅ Yes  | ❌ No     | Depends on implementation |

---

### Summary:

* For **stable & in-place**, `Insertion Sort` and `Bubble Sort` are simplest.
* For large datasets with stability, prefer `Merge Sort` (not in-place).
* For speed and general use, `Quick Sort` is preferred despite being unstable.

```cpp
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int j = i - 1, ele = v[i];
        while (j >= 0 && v[j] >= ele) v[j + 1] = v[j], j--;
        v[j + 1] = ele;
    }
}

int main() {
    vector<int> v = {5, 3, 4, 1, 2};
    insertion_sort(v);
    for (int x : v) cout << x << " ";
}
```

---

### 🔢 Output:

```
1 2 3 4 5
```

