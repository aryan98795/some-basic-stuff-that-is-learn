
---

## 🧟 Zombie Process

A **Zombie process**:

* A child that **has finished** but **still has an entry in the process table**.
* Happens when the **parent doesn't `wait()`** for it.
* It's a "dead" process that hasn't been cleaned up.

---

### 🔢 Code to create a Zombie:

```cpp
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        cout << "Child PID: " << getpid() << " finished\n";
        _exit(0);  // child exits immediately
    } else {
        // Parent does NOT wait
        cout << "Parent PID: " << getpid() << " sleeping...\n";
        sleep(30);  // enough time to inspect zombie via ps
    }
}
```

### 📌 How to check:

Run the code, then in another terminal:

```bash
ps -ef | grep Z
```

You'll see the child process as **`<defunct>`** — it's a zombie until the parent exits or does a `wait()`.

---

## 👻 Orphan Process

An **Orphan process**:

* A child process whose **parent has exited** before the child.
* It gets adopted by the **`init` process (PID 1)** on Linux.

---

### 🔢 Code to create an Orphan:

```cpp
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
using namespace std;

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        sleep(5);  // let parent exit before child
        cout << "Orphan child PID: " << getpid() << " now has parent PID: " << getppid() << '\n';
    } else {
        // Parent exits immediately
        cout << "Parent exiting, PID: " << getpid() << '\n';
        _exit(0);
    }
}
```

### 📌 What you'll see:

The child will print:

```sh
Orphan child PID: 1234 now has parent PID: 1
```

Meaning it's now adopted by `init`.

---

### Summary Table:

| Type   | When it happens                  | Fixed by                        |
| ------ | -------------------------------- | ------------------------------- |
| Zombie | Child exits, parent doesn’t wait | Parent calls `wait()`           |
| Orphan | Parent exits before child        | OS assigns `init` as new parent |

---

