'''
Author : dragon lord

Problem : Chef and Ridges 
Problem Link: https://www.codechef.com/NOV18B/problems/PRDRG/

'''

'''
This problem can be more understood by folding the paper as asked to in the question.
Even after multiple folds we just consider the outermost fold and the ridge formed by it.
The rest of the folds and the ridges formed by them can be ignored.

The 1st fold will place the outermost ridge at a distance of 1/2 from the left side of the original paper.
For the 2nd fold distance of the next ridge formed is 1/4.  (numerator = pow(2,1) - 1 = 1)
For the 3rd fold distance of the ridge formed is  3/8.      (numerator = pow(2,2) - 1 = 3)
For the 4th fold distance of the ridge formed is  5/16.     (numerator = pow(2,3) - 3 = 5)
For the 5th fold distance of the ridge formed is  11/32.    (numerator = pow(2,4) - 5 = 11)
and so on....

'''

import math
import os
import random
import re
import sys


if __name__ == '__main__':

  ''' The max N value is 25 hence we create a result array of size 25+1 '''
  result = [1]*26  

  '''
   Here we find a pattern that shows that the 
   numerator in the next value of N
   is the difference btwn
   the current pow(2,j) of j'th element and the value of numerator for j-1'th element
  '''
  for j in range(1,26):
    result[j]=pow(2,j)-result[j-1]   

  l1 = list(map(int,input().split()))

  ''' output the value for corresponding N '''

  for i in range(1,l1[0]+1):
    print(result[l1[i]-1],pow(2,l1[i]))