# RSA Encryption & Decryption in C++

## Overview
This project implements the **RSA encryption and decryption algorithm** in C++. It allows users to encrypt and decrypt messages using the **public-key cryptography** system. The implementation includes key generation, encryption, and decryption operations based on modular arithmetic.

## Features
- **RSA Key Generation**: Computes public and private key pairs.
- **Modular Exponentiation**: Used for encryption and decryption operations.
- **Prime Factorization**: Extracts prime factors of a given number.
- **Euclidean Algorithm**: Computes the greatest common divisor (GCD) and multiplicative inverse.
- **Character Mapping**: Maps numbers to characters for message encoding and decoding.
- **Error Handling**: Checks for valid public key input.

## Technologies Used
- **C++** (Standard Library)
- **Mathematical Algorithms** (Modular Arithmetic, GCD, Prime Factorization)

## How It Works
### 1. Key Generation
- The user provides two prime numbers `p` and `q`.
- The **modulus `n`** is calculated as:
  
  ```n = p * q```
  
- Compute **Euler’s totient function**:
  
  ```phi(n) = (p-1) * (q-1)```
  
- Choose an **encryption exponent `e`** such that:
  
  ```gcd(e, phi(n)) = 1```
  
- Compute the **decryption exponent `d`** using the **Extended Euclidean Algorithm**.

### 2. Encryption
- Convert the message into a numerical representation.
- Use **modular exponentiation** to encrypt:
  
  ```ciphertext = (message^e) % n```

### 3. Decryption
- Apply **modular exponentiation** with `d`:
  
  ```decrypted_message = (ciphertext^d) % n```

## Code Explanation
### **Main Functions**
- `modular(int base, unsigned int exp, unsigned int mod)`: Implements modular exponentiation.
- `power(int base, int exponent)`: Computes exponentiation.
- `primeFactors(int n)`: Finds prime factors of `n`.
- `Euclid(int a, int b)`: Uses the Euclidean algorithm to compute the GCD.
- `isValid(int p, int q, int e, int cipher)`: Validates public key parameters.

## Usage
### **Compiling the Program**
To compile the program, use:

```bash
g++ rsa.cpp -o rsa

