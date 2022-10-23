#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_a_number(char character) {
    return (character >= '0' && character <= '9');
}

int change_character_case(char *s) {
    int counter = 0;
    while (s[counter] != '\0') {
        if (s[counter] >= 'A' && s[counter] <= 'Z') {
            s[counter] = s[counter] + 32;
        } else if (s[counter] >= 'a' && s[counter] <= 'z') {
            s[counter] = s[counter] - 32;
        }
        counter++;
    }
    return 0;
}

int my_printf(char *format_string, char *param){
	int i;
	for(i=0;i<strlen(format_string);i++){
		
		if((format_string[i] == '#') && (format_string[i+1] == 'K')){
			i++;
			printf("%s",param);
		} else if (format_string[i] == '#'){

			int j = i + 3;                          
			bool is_formatted_properly = false; 
			bool is_not_dot = false;
			if ((is_a_number(format_string[i + 1]))) {  
				j = i + 2;    
				is_not_dot = true;
			}
			
		    while (true) { 
		        if (format_string[j] == '\0') {
		            is_formatted_properly = false;
		            break;
		        }
				else if (format_string[j] == 'K') {
		            is_formatted_properly = true;
		            break;
		        } else {
		        	if (!is_a_number(format_string[j])){   
						is_formatted_properly = false;
		            	break;
					}
		            j++;
		        }
		    }
		    
		    if (is_formatted_properly) {
		    	if (is_not_dot) {
		    		i += 1;	    
				} else {
					i += 2;	   	
				}
		        int expected_string_length = 0;
		        while(format_string[i] != 'K') { 
		            expected_string_length = expected_string_length * 10 + (format_string[i] - '0');
		            i++;
		        }
		        int j = 0;
		        while((param[j] != '\0') && (j < expected_string_length)) {
		            putchar(param[j]);
		            j++;
		        }
		    } else {
		        putchar(format_string[i]);
		    }
		} else {
		    putchar(format_string[i]);
		}
	}
	puts("");
	return 0;
}
