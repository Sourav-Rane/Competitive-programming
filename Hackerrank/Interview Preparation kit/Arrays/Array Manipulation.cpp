/*
Author: dragonlord 

Array Manipulation
Problem link: https://www.hackerrank.com/challenges/crush/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

void solve(ll n , ll m){
  ll a,b,c;
  ll *arr = new ll[n+1] ();
  while(m--){
    cin>>a>>b>>c;
    arr[a-1]+=c;  //adding c to the lower range
    arr[b]+=-c;     //subtracting c from upper range + 1
  }
  auto max = arr[0];
  for(int i =1;i<n;i++)
  {
    arr[i]+=arr[i-1];   //you add every 2 consecutive elements in the array..and constructively get the total sum for all the given queries
    if (arr[i]>max) max =arr[i]; 
  }

  cout<<max;
}



int main() {
  ll n,m;
  cin>>n>>m;
  solve(n,m);
  return 0;
}

