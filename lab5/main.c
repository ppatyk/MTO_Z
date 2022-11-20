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

int my_printf(char *format_string, char *param, char *result){
	int i;
	for(i=0;i<strlen(format_string);i++){
		if((format_string[i] == '#') && (format_string[i+1] == 'g')){   
			strcat(result, param);
			i++;
		} else if (format_string[i] == '#'){
			int j = i + 3;                          
			bool is_formatted_properly = false;
			bool is_not_dot = false;
			if ((is_a_number(format_string[i + 1]))) {   
				j = i + 2;      // j == k
				is_not_dot = true;
			}


