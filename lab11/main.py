#!/usr/bin/env python3

import sys
import re

def replace_letter(number):
    if number == 0:
        return 'a'
    elif number == 1:
        return 'b'
    elif number == 2:
        return 'c'
    elif number == 3:
        return 'd'
    elif number == 4:
        return 'e'
    elif number == 5:
        return 'f'
    elif number == 6:
        return 'g'
    elif number == 7:
        return 'h'
    elif number == 8:
        return 'i'
    elif number == 9:
        return 'j'

def binary_to_letters(binary):
    result = ''
    for i in range(len(binary) - 1, -1, -1):
        letter = binary[i]
        if letter == '1':
            result = replace_letter((len(binary) - 1 - i) % 10) + result
        else:
            result = letter + result
    return result


def decimal_to_binary(param):
    new_param = ''
    decimal = ''
    for i in range(len(param)):
        letter = param[i]
        if letter.isdigit():
            decimal += letter
            if i == len(param) - 1:
                binary = bin(int(decimal)).replace('0b', '')
                new_param += binary_to_letters(binary)
        else:
            if decimal != '':
                binary = bin(int(decimal)).replace('0b', '')
                new_param += binary_to_letters(binary)
                decimal = ''
            new_param += letter
            number = ''
    return new_param



def my_printf(format_string, param):
    new_param = decimal_to_binary(param)
    result = format_string.replace('#d', new_param)
    print(result)

    format_string = format_string.replace('#b', result)
    print(format_string)



data = sys.stdin.readlines()

for i in range(0, len(data), 2):
    my_printf(data[i].rstrip(), data[i+1].rstrip())