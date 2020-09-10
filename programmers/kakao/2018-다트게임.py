import math


def is_point(c):
    return ord('0') <= ord(c) and ord(c) <= ord('9')


def is_bonus(c):
    return c == 'S' or c == 'D' or c == 'T'


def is_option(c):
    return c == '*' or c == '#'


def solution(dartResult):
    answer = [0]
    bonus = {'S': 1, 'D': 2, 'T': 3}
    option = {'#': -1, '*': 2}
    tenCheck = False
    for i in dartResult:
        if is_point(i):
            if tenCheck:
                answer[-1] = 10
            else:
                answer.append(int(i))
                tenCheck = True

        if is_bonus(i):
            answer[-1] = answer[-1] ** bonus[i]
            tenCheck = False

        if is_option(i):
            answer[-1] = answer[-1] * option[i]
            if i == '*':
                answer[-2] = answer[-2] * option[i]
    return sum(answer)
