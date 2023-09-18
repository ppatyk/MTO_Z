#!/usr/bin/env python3

import sys



def my_printf(s):
    alphabet = 'abcdefghij'
    result = ''
    binary_digits = bin(int(s))[2:]  # Konwersja na liczbę binarną i usunięcie prefixu '0b'

    if binary_digits == '0':
        return '0'

    for digit in binary_digits:
        if digit == '0':
            result += '0'
        else:
            result += alphabet[int(digit) - 1]

    return result



data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
