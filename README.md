*This project has been created as part of the 42 curriculum by pnovato-.*

# The Philosophers Project

## Description

The **Philosophers** project is a classic assignment from the 42 curriculum designed to introduce students to the fundamental concepts of **concurrent programming**, **multithreading**, and **resource management** [1]. The project's goal is to implement a solution to the **Dining Philosophers Problem**, a famous thought experiment in computer science that illustrates the challenges of preventing **deadlocks** and **race conditions** when multiple processes or threads compete for a limited number of shared resources.

The simulation involves a set of philosophers who must alternate between eating, sleeping, and thinking, with the constraint that each philosopher requires two forks (shared resources) to eat. The core challenge is to design a protocol that ensures no philosopher starves (livelock) and that the program does not enter a state of deadlock, where all philosophers are waiting indefinitely for a resource held by another [2]. The mandatory part of the project typically requires the use of **threads** and **mutexes** for synchronization.

## Instructions

The project is implemented in C and compiled using a standard `Makefile`.

### Compilation

To compile the source files and create the executable, run the following command in the project's root directory:

```bash
$ make
```

This command will generate an executable file named `philo`.

### Execution

The program must be executed with a specific set of command-line arguments that define the simulation parameters:

```bash
$ ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Argument | Description | Unit |
| :--- | :--- | :--- |
| `number_of_philosophers` | The number of philosophers and, consequently, the number of forks. | N/A |
| `time_to_die` | The time (in milliseconds) after which a philosopher dies if they haven't started eating. | ms |
| `time_to_eat` | The time (in milliseconds) it takes for a philosopher to eat. | ms |
| `time_to_sleep` | The time (in milliseconds) a philosopher spends sleeping. | ms |
| `[optional] number_of_times_each_philosopher_must_eat` | If set, the simulation stops once every philosopher has eaten this many times. | N/A |

### Example

A typical execution might look like this:

```bash
$ ./philo 5 800 200 200 7
```

This command runs a simulation with 5 philosophers, where a philosopher dies after 800ms without food, eats for 200ms, sleeps for 200ms, and the simulation ends when all have eaten 7 times.

## Resources

### Classic References

The following resources provide essential background and technical documentation for the project:

*   **The Dining Philosophers Problem**: The original problem statement and classic solutions, often attributed to Edsger W. Dijkstra [2].
*   **POSIX Threads (Pthreads)**: The standard API for creating and managing threads, mutexes, and semaphores in C/C++ [3].
*   **Concurrency and Synchronization Tutorials**: Articles and guides on managing shared resources, avoiding race conditions, and implementing synchronization primitives like mutexes and semaphores.
*	**How to create and join threads in C (pthreads) by Jacob Sorber**: Series of videos on youtube that may clarify doubts about the threads subject. 

## References

[1] The 42 Philosophers Project: Multithreading & Resource Management. *StudyLib*.
[2] Dining Philosophers Problem. *Wikipedia*.
[3] POSIX Threads (Pthreads) - Linux Man Page. *man7.org*.
[4] How to create and join threads in C (pthreads). - *https://www.youtube.com/watch?v=uA8X5zNOGw8*.