# Blum Blum Shub Algorithm

## Description

Blum Blum Shub (BBS) is a pseudorandom number generator (PRNG) based on the difficulty of factoring large semiprime numbers. The algorithm generates a sequence of pseudorandom bits by computing modular square roots of quadratic residues. The initial inputs required are two large prime numbers, p and q, along with an initial seed value. The BBS algorithm repeatedly squares the seed modulo n, where n = p * q, to produce the next random bit in the sequence. The least significant bit of the squared value becomes the output bit, and the squared value becomes the new seed for the next iteration.

## Use Cases

The BBS algorithm is commonly used in various applications that require random numbers, including cryptography, simulations, and statistical sampling. However, it is generally not recommended for cryptographic purposes due to security concerns.

## Pros

- Theoretical security: BBS is based on the difficulty of factoring large semiprime numbers, which is believed to be a computationally hard problem. The algorithm provides strong security properties in theory.
- Deterministic: BBS is a deterministic PRNG, meaning that given the same inputs, it will always produce the same sequence of random bits. This property can be useful in scenarios where reproducibility is required.

## Cons

- Speed: BBS is relatively slow compared to other PRNG algorithms. The computation of modular square roots can be computationally expensive, especially for large prime numbers p and q.
- Security concerns: BBS has been subject to cryptanalysis, and some weaknesses have been identified. If an attacker can factorize n or determine the seed value, the generated random bits can be predicted.

## Usage

To use the BBS algorithm, create a BlumBlumShub object with the initial seed and prime numbers p and q:
```c++
BlumBlumShub bbs = BlumBlumShub(seed, p, q)
```

To generate a random number, call the generate function with the desired range:
```c++
int8 random_number = bbs.generate(0, 0xff)
```