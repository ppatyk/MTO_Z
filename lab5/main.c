#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *decrement_string(char *str)   
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1;    
    int digit;
    char ch;

    while (i >= 0)  
    {
    	digit = (int)(str[i]) - '0';   
    	digit -= 1;                    
    	if (digit < 0) {               
    		digit = 9;
		}
		ch = digit + '0';             
		str[i] = ch;                        
		i--;                  
    }   
    return str;
}

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}

int decrement_number(char *s) {
    decrement_string(s);    
}

