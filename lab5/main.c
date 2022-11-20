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

    while (i >= 0)  // od ostatniego do pierwszego znaku iterujemy po param2
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