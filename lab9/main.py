import sys
import re


def after_dot_change(number):
    return str((int(number) + 5) % 10)

def before_dot_change(number):
    return str(number) \
        .replace('0','a') \
        .replace('1','b') \
        .replace('2','c') \
        .replace('3','d') \
        .replace('4','e') \
        .replace('5','f') \
        .replace('6','g') \
        .replace('7','h') \
        .replace('8','i') \
        .replace('9','j')


def change_string(wanted_length, param):
    result = ''
    before_dot, after_dot = str(param).split('.')

    before_dot_changed_digits = [before_dot_change(digit) for digit in before_dot]
    result += ''.join(before_dot_changed_digits)


    result += '.'


    actual_length = len(after_dot)

    if wanted_length > actual_length:

        after_dot += '0' * (wanted_length - actual_length)


    after_dot_changed_digits = [after_dot_change(digit) for digit in after_dot]
    result += ''.join(after_dot_changed_digits)

    return result



data=sys.stdin.readlines()
for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
