
// 731-CHECK v1.0.0
// "Reusable checksum component with a public C API"
//
// Check digit calculator component for C and embedded systems
//
// Uses the 7–3–1 weighted checksum algorithm.
//
// Notes:
// - Input is treated as a null-terminated string
// - Only integers (0-9) are processed
// - Non-digit characters are simply ignored
// - Uses a modulo operation to calculate a single check control digit


#include "checksum.h"

uint8_t calculate_check_digit(const char *number_str)
{
    static const uint8_t weights[3] = {7, 3, 1};

    uint16_t sum = 0;
    uint8_t weightindex = 0;

    const char *ptr = number_str;

    // Find string end
    while (*ptr)
        ptr++;

    if (ptr == number_str)
        return 0;

    // Iteration backwards
    while (ptr-- > number_str)
    {
        char c = *ptr;

        if (c >= '0' && c <= '9')
        {
            sum += (uint8_t)(c - '0') * weights[weightindex];
            weightindex = (weightindex + 1) % 3; // Weights applied from right to left!
        }
    }

    return (10 - (sum % 10)) % 10;
}
