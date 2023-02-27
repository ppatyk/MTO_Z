#!/usr/bin/env python3

import re
import sys


def get_replacement_string(expected_length, param):
    result = param \
        .replace('7', '9') \
        .replace('6', '8') \
        .replace('5', '7') \
        .replace('4', '6') \
        .replace('3', '5') \
        .replace('2', '4') \
        .replace('1', '3') \
        .replace('0', '2')

    if expected_length < len(result):
        return result[:expected_length]
    else:
        return result


def my_printf(format_string, param):
    result = format_string

    regex = r'#.(\d+)q'
    pattern = re.compile(regex)

    matches = pattern.finditer(format_string)
    for single_match in matches:
        replacement_string = get_replacement_string(int(single_match.group(1)), param)
        result = result.replace(single_match.group(0), replacement_string, 1)

    print(result)


my_printf("Hello #.5q World", "a1234567890z")

