`heapify()` is **O(n)** when building a **heap from an array** using the **bottom-up approach** (also called "heap construction" or "heap build").

### 🔸 When is it O(n)?

When you do this:

```cpp
make_heap(arr, arr + n); // or custom heapify from index n/2 to 0
```

This is **not** inserting one-by-one, but running `heapify()` from the bottom non-leaf node upwards.

### 🔸 Why O(n) and not O(n log n)?

Because:

* Lower levels of the tree have **more nodes but smaller heights**.
* Total cost = sum of (nodes at each level × height).
* This sum converges to O(n) (mathematically proven by summing a geometric series of depths).

### 🔸 But inserting one by one is O(n log n)

If you insert elements into a heap one by one (`push_heap` or manual insertion), each insertion is O(log n), leading to total O(n log n).

---

🔹 **Conclusion**:

* **Heapify array (bottom-up)** → O(n)
* **Insert one-by-one (top-down)** → O(n log n)

### ✅ PROOF that **heapify()** is **O(n)** (Bottom-Up Heap Construction)

---

### 🔸 Heap Basics:

* In a binary heap of size `n`, we consider the heap as a **complete binary tree**.
* Height of a node = number of edges on the longest path from the node to a leaf.

---

### 🔸 Number of nodes at each height:

In a complete binary tree:

* Number of nodes at height `h` ≈ `n / 2^(h+1)`

### 🔸 Cost of heapify at height `h`:

Each node at height `h` can take at most `O(h)` time to heapify.

### 🔸 Total cost:

Sum over all nodes:

$$
T(n) = \sum_{h=0}^{\log n} \left( \frac{n}{2^{h+1}} \cdot h \right)
$$

This is:

$$
T(n) = n \sum_{h=0}^{\log n} \frac{h}{2^{h+1}} = O(n)
$$

This converges to a constant:

$$
\sum_{h=0}^{\infty} \frac{h}{2^{h+1}} = 1
\Rightarrow T(n) \approx n \cdot 1 = O(n)
$$

---

### ✅ CODE to build heap in **O(n)** using bottom-up `heapify()`

```cpp
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

int main() {
    vector<int> a = {4, 10, 3, 5, 1};
    buildHeap(a);
    for (int x : a) cout << x << " ";
}
```

This builds a **max heap** in **O(n)** time.

---
