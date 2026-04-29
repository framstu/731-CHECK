
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


#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <stdint.h>

uint8_t calculate_check_digit(const char *number_str);

#endif
