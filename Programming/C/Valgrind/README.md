# TL;DR on Valgrind for memory leak detection in C:

Valgrind is a powerful tool used to detect memory leaks, invalid memory accesses, and other memory-related errors in C and C++ programs. It works by running your program in a simulated environment where it tracks memory usage.

- How to use:
    - Compile your program with debugging symbols (-g).
    - Run your program using Valgrind with the command:

    ```sh
    valgrind --leak-check=full ./your_program
    ```

    - --leak-check=full enables detailed leak detection. You can also use --track-origins=yes to track where uninitialized memory was accessed.

## What it shows:

- Valgrind will report memory leaks (unfreed memory), invalid reads/writes, and other issues with memory allocation.
- It gives a summary at the end showing how much memory was leaked and where in your code it occurred.

## Why use it:

- It helps ensure your program doesn't waste memory, which is critical for performance and preventing crashes in long-running applications.