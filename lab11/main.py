#!/usr/bin/env python3

import sys


def convertBin(string):
    converted = ''
    for char in string:
        if 'a' <= char <= 'z':
            char = chr(ord(char))
 
        if char == '0':
            char = 'o'

        converted += char

    return converted


def removeZeros(BinValue, amount):
    BinLen = len(BinValue)
    if BinLen < int(amount):
        for i in range(int(amount) - BinLen):
            BinValue = '0' + BinValue

    return BinValue

def my_printf(format_string,param):
    #print(format_string)
    shouldDo=True
    for idx in range(0,len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'k':
                print(param,end="")
                shouldDo=False
            else:
                print(format_string[idx],end="")
        else:
            shouldDo=True
    print("")

data=sys.stdin.readlines()

for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
