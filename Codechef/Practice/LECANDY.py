"""
Author: dragonlord 

Little Elephant and Candies
Problem link: https://www.codechef.com/problems/LECANDY/

"""

t = int(input())
for _ in range(t):
  n,c=list(map(int,input().split()))
  a = list(map(int,input().split()))
  print("Yes" if sum(a)<=c else "No")