"""
Author: dragonlord 

Arrays: Left Rotation
Problem link: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

"""

n,r = list(map(int,input().split()))
l = list(map(int,input().split()))
ans=list()
partialRotations = r%n

if partialRotations:
    ans.extend(l[partialRotations:])
    ans.extend(l[:partialRotations])
    for i in ans:
        print(i,end=" ")
else:
    for i in l:
        print(i,end=" ")
