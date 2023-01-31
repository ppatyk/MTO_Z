

import sys
import re

def convert_number(param):
    new_str = ''
    for idy in range(0, len(param)):
        if param[idy] == '0':
            new_str += str((9 * 10 + 5) % 10)
        else:
            new_str += str((int(param[idy]) * 9 + 1) % 10)

    return new_str



data = sys.stdin.readlines()

for i in range(0, len(data), 2):
    my_printf(data[i].rstrip(), data[i+1].rstrip())
