/*
Author: dragonlord 

Two Strings
Problem link: https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps


*/


#include <bits/stdc++.h>
using namespace std;



string twoStrings(string s1, string s2) {
  map<char,int> m;
  int done = 0;
  for(auto i: s1) m[i]++;  //count of each character in string 1

  //check wether any character of string 2 is present in string 1
  for(auto i: s2) 
      if(m.find(i) != m.end() ) 
          {
              done = 1;
              break; 
          }

  if(done) return "YES";
  else return "NO";
}



//driver function
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
