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

bool is_string_a_number(char *s) {  
	int counter = 0;
    while (s[counter] != '\0') {
        if (!is_a_hex_number(s[counter])) {
			return false;
		}
        counter++;
    }
    return true;
}

int my_printf(char *format_string, char *param, char *result){
	int i;
	for(i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'j')){ 
			strcat(result, param);
			i += 1;
		}
		else {
			strncat(result, format_string + i, 1);
		}
	}

	return 0;
}