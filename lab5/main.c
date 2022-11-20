#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}

char *decrement_string(char *str)   
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1;  
    int digit;
    char ch;