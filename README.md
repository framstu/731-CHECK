731-CHECK  
v1.0.0

A small C library for calculating a 7–3–1 checksum digit, designed to work well in embedded systems and other portable environments.
The 7–3–1 checksum (sometimes called a control digit) is used to validate numbers, for example in certain animal identification systems.
This project was created mainly for use in bare-metal programming, where a simple, reliable, and dependency-free solution is useful.


Overview

This library computes a single check digit from a numeric string using a repeating weight pattern:

( 7 -> 3 -> 1 -> 7 -> 3 -> 1 -> ... )

Digits are processed from right to left, and the result is reduced to a single digit using modulo 10 arithmetic.


Features
- No dynamic memory allocation
- No external dependencies, except stdint.h
- Portable C code
- Ignores non-digit characters and spaces
- Deterministic and real-time safe
- Suitable for both embedded and desktop use


Algorithm

The checksum uses weighted digit multiplication:
- Each digit is multiplied by a repeating sequence: 7, 3, 1
- The sum is computed


Final check digit is derived using:
check_digit = (10 - (sum % 10)) % 10


File Structure
- checksum.h   Public API, header
- checksum.c   Code base
- main.c       Example file (optional)


Usage
Include the header
#include "checksum.h"


Example
#include <stdio.h>
#include "checksum.h"

int main(void)
{
    const char *input = "123456789";

    uint8_t check = calculate_check_digit(input);

    printf("Check digit: %u\n", check);

    return 0;
}
(This should return the number 7.)


API
calculate_check_digit
uint8_t calculate_check_digit(const char *number_str);


Parameters
number_str — Null-terminated string containing digits


Behavior
- Processes only characters 0-9
- Ignores all other characters, blank spaces included
- Applies 7–3–1 weighting from right to left


Returns
- A single digit (0–9)


Notes
- Input must be null-terminated
- Non-digit characters are ignored (can easily be blocked)
- Designed for embedded and resource-constrained systems

License
This project is licensed under the MIT License
Compatibility

- Tested with GCC


License
This project is licensed under the MIT License


Author
Created by Matias Back, originally as a tool to fix real world problems I encounter.
