# Sequency

Sequency is a lightweight C++ library designed to enable easy and efficient random numbers generation. This library empowers your projects with a touch of unpredictability, bringing in a dynamic element that can enhance a wide variety of applications.

## Core Features

Sequency provides a comprehensive suite of functions to generate random numbers, with a focus on both cryptographic and non-cryptographic algorithms.

### Core Types

The library defines normal types with shorter names for convenience:

- `uint8_t -> int8`
- `uint16_t -> int16`
- `uint32_t -> int32`
- `uint64_t -> int64`

### Utility Functions

In addition to the core random number generation functionality, Sequency also provides several utility functions:

- `is_power_of_two(int64 number)`
- `is_even(int64 number)`
- `is_odd(int64 number)`
- `is_prime(int64 number)`
- `next_power_of_two(int64 number)`
- `previous_power_of_two(int64 number)`
- `next_fibonacci_number(int64 number)`

## Algorithms

The Sequency library includes implementations of a range of algorithms, each suited to different applications and use cases.

### Cryptographic Algorithms

- ChaCha20
- Twofish

### Non-Cryptographic Algorithms

- Blum Blum Shub
- Middle Square
- Park-Miller
- Splitmix64
- Xoroshiro64
- Xorshift32
- Xorshift32WOW
- Xorshift64
- Xorshift64Star

## Building and Installation

[TODO]

## Contributing

We welcome contributions! If you're interested in contributing, here are some ways you can help:

- Reporting Issues: If you find a bug or a feature you think we should implement, please report it to us using the GitHub issue tracker. Please check first that the issue hasn't already been reported. If it has, you can add any additional information in the existing issue.
- Submitting Pull Requests: If you've fixed a bug or implemented a new feature, we would love to see it in our project. Submit a pull request, and we will review it as soon as we can.

Please ensure your code adheres to our coding style before submitting.