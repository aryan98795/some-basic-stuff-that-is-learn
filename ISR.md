### ✅ Interrupt Service Routine (ISR)

An **Interrupt Service Routine (ISR)** is a **special function** that gets **automatically executed** when a hardware or software interrupt occurs.

---

### 🔹 What is an Interrupt?

An interrupt is a **signal** to the processor indicating an event that needs immediate attention (e.g., a button press, timer overflow, data received).

---

### 🔹 Key Features of ISR:

* Triggered **asynchronously** by hardware or software.
* **Very fast** and **short** — should not contain long computations or blocking code.
* Typically used to **handle low-level hardware events** (e.g., read data from UART, acknowledge interrupt).

---

### 🔹 Structure (in C / microcontroller):

```c
void __attribute__((interrupt)) myISR() {
    // clear interrupt flag
    // handle event
}
```

For example, in AVR (Arduino):

```c
ISR(TIMER1_COMPA_vect) {
    // Code to run when Timer1 Compare Match A interrupt occurs
}
```

In ARM Cortex-M (CMSIS):

```c
void TIM2_IRQHandler(void) {
    if (TIM2->SR & TIM_SR_UIF) {  // check update interrupt flag
        TIM2->SR &= ~TIM_SR_UIF;  // clear it
        // handle timer overflow
    }
}
```

---

### 🔹 What Happens During Interrupt:

1. CPU saves current state (PC, registers).
2. Jumps to the ISR.
3. Executes the ISR.
4. Returns to the original task via **Interrupt Return (IRET/RETI)**.

---

### 🔹 Good Practices:

* Keep ISR short.
* Avoid `delay()`, `malloc()`, or heavy computation.
* Use `volatile` for variables shared between ISR and main code.

---
