'''
Author : dragon lord

Problem : Chef and Ridges 
Problem Link: https://www.codechef.com/NOV18B/problems/PRDRG/

'''

import math
import os
import random
import re
import sys

result = [1]*26
for j in range(1,26):
  result[j]=pow(2,j)-result[j-1]

l1 = list(map(int,input().split()))

for i in range(1,l1[0]+1):
  print(result[l1[i]-1],pow(2,l1[i]))