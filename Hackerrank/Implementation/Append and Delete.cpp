#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;                             // no of students
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];                    // enter the grades
    
    for(int i=0;i<n;i++)
    {
        int x = a[i];
        x= (x/5)*5 +5;
        
        if((x-a[i]<3)&&a[i]>=38)      //condition 1
        {
            a[i]=x;
        }
        else
            if(a[i]<38)
                continue;             // condition 2
        else
            if(x-a[i]==3)
            continue;                 // condition 3
        
    }
    
     for(int i=0;i<n;i++)
         cout<<a[i]<<endl;
                       
        
    return 0;
}
