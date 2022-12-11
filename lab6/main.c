
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}

int change_number(char *str) {
    if (!(!str || ! *str))
	{
    	int i = strlen(str) - 1;    
	    int digit;
	    char ch;
	
	    while (i >= 0)  
	    {
	    	digit = (int)(str[i]) - '0';   
	    	digit = (digit * 9 + 1) % 10;  
			ch = digit + '0';             
			str[i] = ch;                         
			i--;                  
	    }   
	}
}