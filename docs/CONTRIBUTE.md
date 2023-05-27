# Project Documentation

Welcome to the project documentation! This document provides guidance on how to contribute to the project and offers an overview of its structure and guidelines. We appreciate your interest and contributions!

## Getting Started

To contribute to the project, follow these steps:

1. Fork the project repository.
2. Create a new branch for your contributions.
3. Make the desired changes to the codebase.
4. Commit your changes to the new branch.
5. Push the new branch to your forked repository.
6. Open a pull request to submit your changes.
7. Wait for the pull request to be reviewed and merged.
8. Celebrate your contribution! 🎉

## Project Structure

The project structure in a organized and clean manner, which i'll explain below:

```
Sequency:
├── docs/
│   └── DOCUMENTATION.md
│   └── CODETEMPLATE.md
│   └── DOCUMENTATIONTEMPLATE.md
├── src/
│   ├── algorithms/
│   │   ├── cryptographically-secure/
│   │   │   └── [Cryptographically Secure Algorithm Files]
│   │   ├── algorithms-docs/
│   │   │   └── [Algorithm Documentation Files]
│   │   └── not-cryptographically-secure/
│   │       └── [Non-Cryptographically Secure Algorithm Files]
│   └── core/
```


Here's a breakdown of the project structure:

- `docs/`: This directory contains the project documentation.
  - `DOCUMENTATION.md`: This file holds the documentation for the project.
  - `CODETEMPLATE.md`: This file contains the code template for the algorithms.
  - `DOCUMENTATIONTEMPLATE.md`: This file contains the documentation template for the algorithms.
- `src/`: This directory contains the project source code.
  - `algorithms/`: This directory holds the algorithm implementations.
    - `cryptographically-secure/`: This directory contains the cryptographically secure algorithm files.
      - `[Cryptographically Secure Algorithm Files]`: These are the files for the cryptographically secure algorithms you add.
    - `algorithms-docs/`: This directory holds the documentation files for the algorithms.
      - `[Algorithm Documentation Files]`: These are the documentation files for the algorithms.
    - `non-cryptographically-secure/`: This directory contains the non-cryptographically secure algorithm files.
      - `[Non-Cryptographically Secure Algorithm Files]`: These are the files for the non-cryptographically secure algorithms you add.

  - `core/`: This directory contains the core files of the project.

## Development Setup

[TODO]

## Contribution Guidelines

When making contributions to the project, please adhere to the following guidelines:

- Use the provided code template (see `docs/CODETEMPLATE.md`) when writing your algorithm code.
- Follow the documentation template (see `docs/DOCUMENTATIONTEMPLATE.md`) when documenting your algorithm.
- Write clean and well-organized code. If possible, add comments to enhance code readability.
- Place your code in the appropriate folder: `src/algorithms/cryptographically-secure` or `src/algorithms/not-cryptographically-secure`, depending on the nature of your algorithm.
- Use meaningful and understandable variable names.
- Strive for efficient and optimized code.
- Use descriptive file names that match the algorithm being added. For example:
    - `mersenne-twister.h` ✅
    - `mersenneTwister.h` ✅
    - `MersenneTwister.h` ✅
    - `MERSENNE_TWISTER.h` ❌
    - `mt.h` ❌
    - `MTPRNG.h` ❌

## Examples or Use Cases

[TODO]

We hope this documentation helps you understand the project and guides you in making meaningful contributions. Thank you for your interest and support!
