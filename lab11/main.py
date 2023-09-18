#!/usr/bin/env python3

import sys
import re

def decimal_to_binary(param):
    new_param = ''
    decimal = ''
    for letter in param:
        if letter.isdigit():
            decimal += letter
        else:
            if decimal != '':
                binary = bin(int(decimal)).replace('0b', '')
                new_param += binary
            new_param += letter
            number = ''
    return new_param



def my_printf(format_string, param):
    result = ""
    new_param = decimal_to_binary(param)

print(decimal_to_binary('5a5a5'))


data = sys.stdin.readlines()
for i in range(0, len(data), 2):
my_printf(data[i].rstrip(), data[i+1].rstrip())
