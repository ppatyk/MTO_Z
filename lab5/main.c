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

            while (true) { 
		        if (format_string[j] == '\0') {
		            is_formatted_properly = false;
		            break;
		        }
				else if (format_string[j] == 'g') {
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



int main(int argc, char *argv[]){
	FILE *fp_input;
	FILE *fp_output;
	char *buf = NULL, *buf2 = NULL, result[1024];
	size_t len = 0;
	ssize_t read, read2;

	fp_input = fopen("input.txt", "r");
	fp_output = fopen("output.txt", "w");

	while(true) {
		read = getline(&buf, &len, fp_input);
		read2 = getline(&buf2, &len, fp_input);
		memset(result, 0, 1024);
