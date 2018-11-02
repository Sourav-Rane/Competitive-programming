/*
Author : dragonlord

APPLE AND ORANGE
Problem link: https://www.hackerrank.com/challenges/apple-and-orange/problem

*/


#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int s,t;                   // house co-ordinates
    int a,b;                   //apple & orange tree co-ordinates
    int m,n;                   //#apples , #oranges
    
    int apple =0, orange =0;
    
    
    cin>>s>>t;
    cin>>a>>b;
    cin>>m>>n;
    
    int ap[m], o[n];
    
    for(int i=0;i<m;i++)
        cin>>ap[i];
    
    for(int i=0;i<n;i++)
        cin>>o[i];
    
    
    
    for(int i=0;i<m;i++)
    {
        
        if((ap[i]+a >=s)&&(ap[i]+a<=t))
            apple++;
        
    }
    
     for(int i=0;i<n;i++)
    {
       
        if((o[i]+b<=t)&&(o[i]+b>=s))
            orange++;
        
    }
    cout<<apple<<endl<<orange;
    
                      
        
        
    
    return 0;
}
