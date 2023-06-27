# _printf()

This is a simulation of printf() function in standard input/output library (C programming language).

## Usage
_printf("format", arguments);

**Example:** _printf("This is the number fifteen: %i", 15)
**Output:** This is the number fifteen: 15

## Capabilities
The function can only handle the following conversion specifiers
1. %c
2. %s
3. %d
4. %i
5. %%

## Limitations
1. Does not replicate the buffer handling of the C library printf function
2. Does not handle the flag characters
3. Does not have to handle field width
4. Does not have to handle precision
5. Does not have to handle the length modifiers

Written with love by Eric and Denis.
