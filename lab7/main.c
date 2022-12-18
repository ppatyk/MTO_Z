#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_hex_number(char character) {
    return ((character >= '0' && character <= '9') || (character >= 'a' && character <= 'f'));
}

int change_number(char *str) {
    if (!(!str || ! *str))
	{
    	int i = strlen(str) - 1;    
	    int asci_digit;
	    char ch;
	
	    while (i >= 0)  
	    {
	    	asci_digit = (int)(str[i]);
	    	if ((asci_digit >= 'a') && (asci_digit <= 'f')){  
	    		ch = asci_digit + 6;
			} else {
				ch = asci_digit;        
			}
			str[i] = ch;                        
			i--;                  
	    }   
	}
}