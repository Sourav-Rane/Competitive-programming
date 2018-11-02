"""
Author: dragonlord 

2D Array - DS
Problem link: https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

"""


matrix = [[int(x) for x in input().split()] for i in range(6)]
m = -99999
for i in range(4):
    s=0
    for j in range(4):
        s=matrix[i][j]+matrix[i][j+1]+matrix[i][j+2]+matrix[i+1][j+1]+matrix[i+2][j]+matrix[i+2][j+1]+matrix[i+2][j+2]
        if s > m:
            m=s
print(m)