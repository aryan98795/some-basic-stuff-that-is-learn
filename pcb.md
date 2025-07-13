### ✅ PCB (Process Control Block) in Operating Systems

---

## 🔹 What is PCB?

**PCB (Process Control Block)** is a **data structure used by the operating system** to **store all information about a process**.
---

## 🔹 Contents of PCB

| Component                  | Description                                       |
| -------------------------- | ------------------------------------------------- |
| **Process ID (PID)**       | Unique identifier for the process                 |
| **Process State**          | Ready, Running, Waiting, Terminated, etc.         |
| **Program Counter (PC)**   | Address of the next instruction to execute        |
| **CPU Registers**          | Saved CPU register values (for context switching) |
| **Memory Management Info** | Page tables, segment tables, base/limit registers |
| **Accounting Info**        | CPU time used, priority, limits, etc.             |
| **I/O Status Info**        | List of open files, I/O devices allocated         |
| **Parent/Child Info**      | Parent PID, child processes                       |
| **Scheduling Info**        | Priority, queue pointers                          |

---
Each process has **its own PCB**, stored in a **process table** in the OS.

---

## 🔹 When is PCB Used?

| Situation           | Use of PCB                       |
| ------------------- | -------------------------------- |
| Context Switching   | Save and restore register values |
| Process Scheduling  | Select next process to run       |
| Process Termination | Remove PCB                       |
| Process Creation    | Allocate new PCB                 |

---

## 🧠 Summary

| Term    | PCB (Process Control Block)                 |
| ------- | ------------------------------------------- |
| What    | Data structure holding process info         |
| Used By | OS Scheduler, Memory Manager, Dispatcher    |
| Stores  | State, PID, PC, registers, I/O, memory info |
| Purpose | Manage, control, and switch processes       |

---
