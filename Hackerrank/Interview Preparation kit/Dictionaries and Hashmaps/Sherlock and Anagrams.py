'''
  Author : dragonlord

  Sherlock and Anagrams
  Problem link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D=dictionaries-hashmaps
  
'''


'''
Two string are anagrams if and only if for every letter occurring in any of them the number of its occurrences is equal in both the strings.

This definition is crucial and will lead to the solution. Since the only allowed letters are lowercase English letters, from a to z, the alphabet size is constant and its size is 26 . This allows us to assign a constant size signature to each of the substring of s.

A signature of some string w  will be a tuple of 26 elements where the i-th element denotes the number of occurrences of the -th letter of the alphabet in w.

So, for example, if w = "mom" 
then its signature is [0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,0,0] ,
 so the only non-zero elements are the ones corresponding to letter m  with value of 2 and letter o with value of 1.

Notice, that any string that is an anagram of "mom" will have the same signature as "mom" , and every string that is not an anagram of "mom" will definitely have a different signature.

This concept of signatures allows the following approach.

Let's iterate over all substrings of s and for each fixed substring let's compute its signature and add that signature to signatures hashmap, where signature[sig] denotes the number of substrings of s with a signature sig.

Finally, the only remaining thing to do is to get the number of pairs of substrings of s that are anagrams. It's easy to do having our hashmap. Notice that if there are n  substrings of s with signature sig , then they can form n*(n-1)/2 pairs of substrings with signature , so we can just iterate over all values in the hashmap and for each value n add n*(n-1)/2 to the final result.


'''



import string

Alpha = string.ascii_lowercase  #basically creates a string with all lowercase alphabets
n = int(input())

for _ in range(n):
    s = input()
    d = dict()

    sig = []  #to store the signature of the string

    #find all substrings
    for start in range(len(s)):
        for finish in range(start,len(s)):

            #for each substring calculate the signature
            sig = [0 for i in Alpha]
            for i in s[start:finish+1]:
                sig[ord(i)-ord(Alpha[0])]+=1
            
            #convert the list to tuple to use as a key
            sig = tuple(sig)
            d[sig] = d.get(sig,0)+1

    c = 0
    for i in d.values():
        c+= i*(i-1)//2
    print(c)
