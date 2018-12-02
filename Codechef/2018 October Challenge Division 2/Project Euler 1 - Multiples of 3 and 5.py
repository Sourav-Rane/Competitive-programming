'''
Author : Dragon lord

Problem:  Multiples of 3 and 5
Problem Link:  https://www.hackerrank.com/contests/projecteuler/challenges/euler001

'''



'''
This question involves operations from number theory.
We need to find the sum of all multiples of 3 or 5 and sum them up.
General approach would be to run a loop from 1 to n and check the divisiblity.  :  O(n*t)
A faster approach would in the following manner:
  We know that the sum of first n natural numbers can be calculated by using the formula : n(n+1)/2

  ie.. 1+2+3+4......+n = n(n+1)/2   ----------------- (1)

  if we multiply the equation  (1) by k on both sides we obtain,

  1k+2k+3k+4k+......+nk = kn(n+1)/2 ----------------- (2)

  The equation 2 now gives you gives you the sum of first n multiples of k.

So now all we have to do is to calculate the sum of first k multiples of 3 and 5  before n.
k can be obtained by dividing n by 3 and 5 .

Ans : sum of multiples of 3 + sum of multiples of 5 - sum of multiples of 15

Note : some numbers will be repeated as they are divisible by both 3 and 5. Hence these numbers can be avoided by calculating their
sum using the LCM of 3 and 5 , which is 15. Subtract this value from the final answer


'''

t = int(input())
for _ in range(t):
    n = int(input())
    c=0
    if n%5==0:                                # number of multiples of 5 before n
        five = n//5 -1
    else:
        five = n//5
        
    if n%3 ==0:                               # number of multiples of 3 before n
        three = n//3 -1
    else:
        three = n//3
        
    if n%15 == 0:                             # number of multiples of 15 before n
        teen = n//15 - 1
    else:
        teen = n//15
        
   
    print(int(5*five*(five+1)//2 + 3*three*(three+1)//2) - 15*teen*(teen+1)//2)