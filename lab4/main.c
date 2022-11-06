#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *strrev(char *str)   
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];                
        str[i] = str[j];           
        str[j] = ch;                
        i--;                                                   
        j++;
    }
    return str;
}

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}

int change_character_order(char *s) {
    int counter = 0;
    strrev(s);    
}

bool is_string_a_number(char *s) {   
	int counter = 0;
    while (s[counter] != '\0') {
        if (!is_a_number(s[counter])) {
			return false;
		}
        counter++;
    }
    return true;
}