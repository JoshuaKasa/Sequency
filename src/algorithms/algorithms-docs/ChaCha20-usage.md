# ChaCha20 PRNG Algorithm

## Description

ChaCha20 is a stream cipher algorithm designed by Daniel J. Bernstein. It operates on a 4x4 matrix of 32-bit words and undergoes multiple rounds of mixing operations to generate a pseudorandom stream of bits. The algorithm utilizes a secret key and a nonce to produce the output. Simple arithmetic operations like addition, rotation, and XOR are employed to ensure fast and secure generation of random-like sequences.

## Use Cases

ChaCha20 is commonly used in encryption protocols such as Transport Layer Security (TLS), Internet Key Exchange (IKE), and secure messaging applications like Signal. It can also be utilized for generating random numbers in general-purpose programming.

## Pros

- Security: ChaCha20 is considered highly secure and resistant to cryptanalysis. It has undergone extensive scrutiny and analysis by the cryptographic community.
- Speed: The algorithm is designed to be highly efficient, providing excellent performance on modern computer architectures, especially when implemented in hardware or optimized software.
- Simplicity: ChaCha20 has a relatively simple design, making it easier to implement correctly and audit for potential vulnerabilities.
- Resistance to side-channel attacks: ChaCha20 is less susceptible to side-channel attacks compared to other algorithms like AES, making it a suitable choice for environments where such attacks are a concern.

## Cons

- Lack of widespread adoption: Although ChaCha20 is gaining popularity, it is not as widely supported as the Advanced Encryption Standard (AES) in some cryptographic libraries or applications.
- Key management: ChaCha20 does not provide built-in key management or authentication mechanisms. These aspects need to be addressed separately when using the algorithm for secure communications.
- Limited block size: ChaCha20 generates a stream of bits rather than encrypting fixed-size blocks, which may limit its applicability in certain scenarios that require specific block sizes.

## Usage

To use the ChaCha20 PRNG algorithm, generate a 32-byte key and a 12-byte nonce:

```c++
int8 key[32] = { 32 random bytes };
int8 nonce[12] = { 12 random bytes };
```

Create a ChaCha20 object using the generated key and nonce:
```c++
ChaCha20 chacha20 = ChaCha20(key, nonce);
```

To generate a random number, call the generate function with the desired range:
```c++
int8 random_number = chacha20.generate(0, 0xff);
```