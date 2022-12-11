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
		if((format_string[i] == '#') && (format_string[i+1] == '.') && (format_string[i+2] == 'g')){   
			strcat(result, param);
			i += 2;
		} else if (format_string[i] == '#' && format_string[i+1] == '.'){ 	
			int j = i + 2;                          
			bool is_formatted_properly = false;
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
		    
		    if (is_formatted_properly) {
		    	i += 2;
		        int expected_string_length = 0;
		        while(format_string[i] != 'g') { 
		            expected_string_length = expected_string_length * 10 + (format_string[i] - '0');
		            i++;
		        }
		        int j = 0;
		        while((param[j] != '\0') && (j < expected_string_length)) {
		        	strncat(result, param + j, 1);
		            j++;
		        }
		    } else {
		    	strncat(result, format_string + i, 1);
		    }
		}
		else {
			strncat(result, format_string + i, 1);
		}
	}

	return 0;
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

		if (read == -1 || read2 == -1) {
			break;
		} else {
			buf[strcspn(buf, "\n")] = 0;
			buf2[strcspn(buf2, "\n")] = 0;
			
			if(is_string_a_number(buf2)) {    
				printf("\nCorrect Input Format");
			} else {
				printf("\nSecond input parameter is not a number!");
				break;
			}

			change_number(buf2);    
			my_printf(buf, buf2, result);    

			fputs(result, fp_output);
			fputs("\n", fp_output);
		}
	}

	fclose(fp_input);
	fclose(fp_output);


	return 0;
}


