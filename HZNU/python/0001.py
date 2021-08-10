#!/usr/bin/env python
# -*- coding: UTF-8 -*-
'''
@Author  ：fangpf
@Date    ：2021/8/4 9:37 
'''


import sys

for line in sys.stdin:
    print(line.split()[0] + line.split()[1])