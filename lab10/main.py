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

