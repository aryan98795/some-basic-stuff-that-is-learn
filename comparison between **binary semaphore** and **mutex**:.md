
| Feature                         | **Binary Semaphore**                                    | **Mutex**                                                |
| ------------------------------- | ------------------------------------------------------- | -------------------------------------------------------- |
| **Definition**                  | A synchronization object that allows 0 or 1 value.      | A locking mechanism used to provide mutual exclusion.    |
| **Ownership**                   | No concept of ownership; any thread can signal or wait. | Only the thread that locks it should unlock it.          |
| **Use Case**                    | Used for signaling between threads or processes.        | Used to protect shared resources from concurrent access. |
| **Unlocking**                   | Can be released (signaled) by any thread.               | Must be unlocked only by the locking thread.             |
| **Priority Inversion Handling** | Not handled.                                            | Often supports priority inheritance.                     |
| **Context**                     | Can be used across processes (if shared memory used).   | Typically used within the same process/thread space.     |
| **Error Prone**                 | More prone due to lack of ownership.                    | Safer due to strict ownership rules.                     |

### Summary:

* Use **mutex** when you need mutual exclusion on a resource.
* Use **binary semaphore** when signaling is needed between threads or tasks.
