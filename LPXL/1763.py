#!/usr/bin/env python
# -*- coding: UTF-8 -*-
'''
@Author  ：fangpf
@Date    ：2021/8/26 19:16 
'''

import io
import sys
# sys.stdout = io.TextIOWrapper(sys.stdout.buffer,encoding='utf8')


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


if __name__ == '__main__':
    while True:
        a = input()
        b = input()
        # print(a, b)
        c = gcd(int(a), int(b))
        print(c)