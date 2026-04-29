
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
//
// Designed to be light, reusable and portable
//
// 731-CHECK v1.0.0
// Created by: Matias Back
// License: MIT


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "checksum.h" // Declaration of checksum function

#define BUFFER_SIZE 32	// Max input length incl newline + null

int main(void)
{
    char series[BUFFER_SIZE]; // Stores user input, numbers expected
	
	printf("\n--- 731-CHECK (demo) ---\n\n");
	printf("Demo of 7–3–1 checksum component.\nNon-digit characters are ignored.\n");
    while (1)
    {
        printf("Enter number without check digit (empty to quit): ");

        if (fgets(series, sizeof(series), stdin) == NULL)
            return 0;

        // Remove newline for predictable behavior
        series[strcspn(series, "\n")] = '\0';

        if (series[0] == '\0')
       	{
       		printf("\nBye!\n");
            return 0;
        }

        printf("Check digit: %u\n\n",
               calculate_check_digit(series));
    }
}
