
> **Why don’t we pass two parameters when overloading binary operators like `+`, `-`, `*`, etc. in C++?**

Let’s break this down with **clarity and example**:

---

### 🔸1. Binary Operator Overloading: What’s happening?

Suppose you write:

```cpp
A + B;
```

This is syntactic sugar for:

```cpp
A.operator+(B);
```

So you are calling a **member function** on object `A`, and passing `B` as the only argument.

---

### 🔹2. Then why only **one parameter**?

Because the **left-hand side (LHS)** of the operator (i.e., `A`) is **implicitly passed as `this`** when it's a **member function**.

✅ So you only need to pass **the RHS operand** (`B`) as the **single parameter**.

---

### ✅ Example:

```cpp
class Complex {
public:
    int real, imag;

    Complex(int r, int i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

Here:

* `c1 + c2` is internally `c1.operator+(c2)`
* `c1` is `this`
* `c2` is `other`

So, only one parameter (`other`) is explicitly written.

---

### 🔸3. But what if I want to pass both?

You can do that too — by using a **non-member function**:

```cpp
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}
```

In this case, you must provide **two parameters** because you're not inside a class — no `this` pointer.

---

### 🔍 Summary Table:

| Type of Overload | Parameters | Why                             |
| ---------------- | ---------- | ------------------------------- |
| Member function  | 1 param    | `this` is implicit              |
| Non-member       | 2 params   | No `this`, both operands passed |

---
