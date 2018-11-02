/*
Author: dragonlord 

Just Next
Problem link: https://www.spoj.com/problems/JNEXT/

*/


#include <bits/stdc++.h>
using namespace std;


int main() {
  int i , j,n,t;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
      cin>>a[i];

    for(i=n-2;i>-1;i--)  // traverse from end till u find the array to be sorted in descending order
      if(a[i]<a[i+1])     // break on the dip - i
        break;
        
    if (i==-1){
      cout<<-1<<endl;
      continue;
    }


    for(j=i+1;j<n;j++)   // incase of multiple same values take the last digit from the repeated values
      if(a[j]<=a[i])
        break;

    swap(a[i],a[j-1]);  //swap last number and the dip number
    sort(a+i+1,a+n);    //sort all the numbers from the dip location till the last of the array

    for(i=0;i<n;i++)
      cout<<a[i]<<"";
    
    cout<<endl;

  
  }
}