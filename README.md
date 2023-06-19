# Banker's Algorithm for Resource Allocation

This project implements the Banker's Algorithm, a deadlock avoidance algorithm used in resource allocation in operating systems. The algorithm ensures that processes can request and release resources in a safe and deadlock-free manner.

## Introduction

The Banker's Algorithm is an important concept in operating systems that helps prevent deadlock in resource allocation. It considers the maximum resource requirements of each process, the resources currently allocated to each process, and the available resources. By analyzing these factors, the algorithm determines whether a particular resource request should be granted or denied to avoid potential deadlocks.

## Features

- Accepts the number of resources and processes as input.
- Takes input for the total number of resources available.
- Accepts the allocated resources for each process.
- Accepts the maximum required resources for each process.
- Checks if the system is in a safe state or an unsafe state.
- Outputs the safe sequence if the system is in a safe state.

## Getting Started

To get started with the Banker's Algorithm project, follow these steps:

1. Clone the repository: `git clone https://github.com/ShayanAkhtar/Bankers_Algorithm`
2. Compile the code using a C++ compiler: `g++ main.cpp -o banker_algorithm`
3. Run the executable: `./banker_algorithm`
4. Follow the prompts to input the required information.
5. View the output to determine if the system is in a safe or unsafe state.

## Requirements

- C++ compiler

## Usage

1. When prompted, enter the number of resources and processes.
2. Enter the total number of resources available.
3. Provide the allocated resources for each process.
4. Enter the maximum required resources for each process.
5. The program will determine if the system is in a safe or unsafe state.
6. If the system is safe, it will display the safe sequence.

## Example

```
Enter the number of Resources: 3
Enter the total number of resources for R1: 10
Enter the total number of resources for R2: 5
Enter the total number of resources for R3: 7

Enter the number of Processes: 4

Enter the allocated resources for each process:
Enter the number of resources allocated to P1 for R1: 0
Enter the number of resources allocated to P1 for R2: 1
Enter the number of resources allocated to P1 for R3: 0

...

Safe Sequence: P2 → P3 → P1 → P4
Safe State
```

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

This implementation of the Banker's Algorithm is based on the principles and concepts taught in operating systems courses and textbooks. Special thanks to the open-source community for their valuable contributions and resources.

## Contact

For any inquiries or suggestions, please feel free to reach out to [Shayan Akhtar](mailto:shayantanoli38@gmail.com).

Enjoy using the Banker's Algorithm for resource allocation!
