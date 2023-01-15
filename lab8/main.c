#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_hex_number(char character) {
    return ((character >= '0' && character <= '9') || (character >= 'a' && character <= 'f'));
}

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}
