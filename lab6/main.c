
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






int main(int argc, char *argv[]){
	FILE *fp_input;
	FILE *fp_output;
	char *buf = NULL, *buf2 = NULL, result[1024];
	size_t len = 0;
	ssize_t read, read2;

	fp_input = fopen("input.txt", "r");
	fp_output = fopen("output.txt", "w");