"""
Author: dragonlord 

New Year Chaos
Problem link: https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
"""

def bribe(ppl,n):
    c=0
    for i in range(n-1,-1,-1):
        if ppl[i]-(i+1)>2:   # if the person has bribed more than 2 ppl then quit
            print("Too chaotic")
            return
        
        for j in range(max(0,ppl[i]-2),i): #[i]-2 as an element could have bribed 2 ppl atmost and gone ahead...so we check from there till i
            if ppl[j]>ppl[i]:
                c+=1

    print(c)


t= int(input())
for _ in range(t):
    n = int(input())
    l=list(map(int,input().split()))
    bribe(l,n)
