"""
Author: dragonlord 

Chef and Serves
Problem link: https://www.codechef.com/OCT18B/problems/CHSERVE/

"""


t = int(input())
for _ in range(t):
  p,q,k = list(map(int,input().split()))
  if (p+q)%(2*k) < k:
    print("CHEF")
  else:
    print("COOK")