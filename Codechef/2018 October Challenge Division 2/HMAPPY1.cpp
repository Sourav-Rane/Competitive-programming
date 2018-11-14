/* 
Author : Dragon lord

Problem:  Appy Loves One
Problem Link:  https://www.codechef.com/NOV18B/problems/HMAPPY1/

*/

/*
This problem can be solved by considering the following example :
Let the binary string be :  1 0 1 1 1 1 0 1 1 1 1 1 0 1

Lets specify their indices as follows:
index: 0  1  2  3  4  5  6  7  8  9  10 11 12 13
       1  0  1  1  1  1  0  1  1  1  1  1  0  1


Here we consider 4 cases :
                                                                                     [startPtr, endPtr]
1) The number of continuous 1s at the start of the string.                         - [0,0] 
2) The number of continuous 1s at the end of the string.                           - [13,13]
3) The largest number of continuous 1s  in btwn the above case 1 and case 2.       - [7,11]
4) The 2nd largest number of continuous 1s in btwn the above case 1 and case 2.    - [2,5]


Here for each case we keep a track of start and end pointers of the sequence.
Then we go trough each query and increment the pointers accordingly  (rotating the pointers along the string).

When we come across a '!' in the query we increment the pointers.
When we come across a '?' we then find the lengths of the ones based on the following cases written in the program.
Those cases help us determine the different lengths of the 1 sequences and push them into a priority queue.
At the end of the calculation we pop of the top most value in the queue to get the maximum length of all.

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define forup(u,v) for(ll i=u;i<v;i++)
#define fordown(u,v) for(ll i=u;i>v;i--) 

int listfront=-1 , listfrontend=-1;  // 2 pointers for starting sequence   [lf , lfe]

int listback=-1, listbackend=-1; // 2 pointers for ending sequence         [lb , lbe]

int remain_forward=0,remain_backward=0;  // 2 pointers to denote the remaning string after finding starting and ending sequence  [rf, rb]

int start=-1,end_of_list=-1;  // 2 pointers for largest sequence in btwn   [s, eo1]

int start2 = -1 , end_of_start2 = -1;   // 2 pointers for 2nd largest sequence in btwn  [s2, eo2]
 

// Find the length of the continuous 1s at the START of the binary string
void find_length_at_start(vector <ll> seq,ll n){
  listfront=0;
    forup(1,n)
    {
      if(!seq[i])
        {
          listfrontend=i-1;
          remain_forward=i;
          return;
        }
      if(i+1==n){
        listfrontend=n-1;
        remain_forward=n-1;
      }
    }
}


// Find the length of the continuous 1s at the END of the binary string
void find_length_at_end(vector <ll> seq, ll n){
    listbackend=n-1;
    fordown(n-1,remain_forward-1)
    {
      if(!seq[i])
      {
        listback=i+1;
        remain_backward = i;
        return;
      }
    }


}



// Find the largest sequence in btwn START and END of the binary string.
void find_the_remaining_length(vector <ll> seq, ll n){
  ll a,b,m=0;
  a=-1,b=-1;
  if(remain_forward==remain_backward and seq[remain_forward]==0) 
    return;
  else
  if(remain_forward == remain_backward){
    start = remain_forward;
    end_of_list = start;
    return;
  }

  forup(remain_forward,remain_backward){
    if(seq[i])
    {
      a=i;
      for(ll j=i+1; j<n;j++) 
        if(seq[j]==0){
          b=j-1;
          i=j;
          break;
        }else 
        if(j+1==n) 
          {
            b = j;
            i=j+1;
          }
    }

    if((b-a) >= m and a!=-1 and b!=-1)
    {
      m=b-a;
      start=a;
      end_of_list=b;
    }
  }


}





// Find the 2nd largest sequence in btwn START and END of the binary string.
void find_the_remaining_lengthpart2(vector <ll> seq, ll n){
  ll a,b,m=0,mini = 99999;
  a=-1,b=-1;
  if(remain_forward==remain_backward and seq[remain_forward]==0) 
    return;

  forup(remain_forward,remain_backward){
    if(seq[i])
    {
      a=i;
      for(ll j=i+1; j<n;j++) 
        if(seq[j]==0){
          b=j-1;
          i=j;
          break;
        }else 
        if(j+1==n) 
          {
            b = j;
            i=j+1;
          }
    }

    if((b-a) <= (end_of_list - start) and a!=-1 and b!=-1 and abs((b-a) - (end_of_list - start)) < mini and b!=end_of_list and a!=start)
    {
      mini=abs((b-a) - (end_of_list - start));
      start2=a;
      end_of_start2=b;
    }
  }


}




int main(){

  ll n,q,k,x;

  cin>>n>>q>>k;
  vector <ll> seq;
  string s;
  
  forup(0,n) cin>>x, seq.push_back(x);
  cin>>s;
 
  remain_backward=n-1;

  // If the string starts with 1
  if(seq[0]) find_length_at_start(seq,n);

  // If the string ends with 1
  if(seq[n-1]) find_length_at_end(seq,n);

  find_the_remaining_length(seq,n);
  if(start!=-1)find_the_remaining_lengthpart2(seq,n);

    
  for(ll i =0; i<q;i++){
    if (s[i]=='!')
    {
      if(listfront!=-1)
      {
        listfront = (listfront+1)%n;
        listfrontend = (listfrontend+1)%n;
      }

      if(listbackend!=-1)
      {
        listbackend=(listbackend+1)%n;
        listback = (listback+1)%n;
      }

      if(start!=-1)
        {
          start = (start+1)%n;
          end_of_list = (end_of_list+1)%n;
        }
    }
    else{

      priority_queue <int> pq;

      //case 0  - The string has all zeroes
      if(listfront==-1 and start==-1 and listback==-1) pq.push(0);

      //case 1  -  { [lf , lfe]... [s2, eo2]...[s, eo1]...[lb , lbe] }
      if(listfront <= listfrontend and start <= end_of_list and listback <= listbackend )
      {
        
        if(listfrontend!=-1) pq.push(listfrontend - listfront + 1);
        if(start!=-1) pq.push(end_of_list - start + 1);
        if(listback != -1) pq.push(listbackend - listback + 1);
        if(start2 != -1 ) pq.push(end_of_start2 - start2 + 1);

                  
        if(listfrontend!=-1 and listfrontend+1==listfront) pq.push(n);
        if (listfrontend+1 == start and listfrontend!=-1) pq.push(end_of_list - listfront + 1);
        if (end_of_list +1 == listback and end_of_list!=-1 ) pq.push(listbackend-start+1);
        if (listfrontend+1 == start and end_of_list +1 == listback and listfrontend!=-1 and end_of_list!=-1) pq.push(listbackend-listfront + 1);


        if (listbackend+1 == listfront and listbackend!=-1 ) pq.push(listfrontend -listback+1);
        if (listfrontend+1 == start and listfrontend!=-1 ) pq.push(end_of_list - listfront + 1);
        if (listbackend+1 == listfront and listfrontend+1 == start and listbackend!=-1 and listfrontend!=-1 ) pq.push(end_of_list - listback + 1);


        if (end_of_list + 1 == listback and end_of_list!=-1) pq.push(listbackend - start + 1);
        if (listbackend+1 == listfrontend and listbackend!=-1) pq.push(listfrontend - listback + 1);
        if (end_of_list + 1 == listback and listbackend+1 == listfrontend and end_of_list!=-1 and listbackend!=-1) pq.push(listfrontend - start + 1);

        if(pq.top() <= k) cout<<pq.top()<<endl;
        else cout<<k<<endl;

      }
      
      //case 3   -  { eo1]...[lb , lbe]...[lf , lfe]... [s2, eo2]...[s  }
      if(listfront <= listfrontend and start > end_of_list and listback <= listbackend)
      {
        if(listfrontend!=-1) pq.push(listfrontend - listfront + 1);
        if(listback != -1) pq.push(listbackend - listback + 1);
        pq.push(n-start);
        pq.push(end_of_list+1);
        if(start2 != -1 ) pq.push(end_of_start2 - start2 + 1);


        if(listfrontend!=-1 and listfrontend+1==listfront) pq.push(n);

        if(end_of_list+1==listback and end_of_list!=-1) pq.push(listbackend+1);
        if(listfrontend+1==start and listfrontend!=-1) pq.push(n-listfront);
        if(listbackend+1==listfront and listbackend!=-1) pq.push(listfrontend-listback+1);

        if(end_of_list+1==listback and listbackend+1==listfront and end_of_list!=-1 and listbackend!=-1) pq.push(listfrontend+1);
        if(listbackend+1==listfront and listfrontend+1==start and listbackend!=-1 and listfrontend!=-1) pq.push(n-listback);
        if(end_of_list+1==listback and listfrontend+1==start and listbackend+1==listfront and end_of_list!=-1 and listfrontend!=-1 and listbackend!=-1) pq.push(n);


        if(pq.top() <= k) cout<<pq.top()<<endl;
        else cout<<k<<endl;

      }

      //case 2  -  {  lbe]...[lf , lfe]... [s2, eo2]...[s, eo1]...[lb  }
      if(listfront <= listfrontend and start <= end_of_list and listback > listbackend)
      {
        if(listfrontend!=-1) pq.push(listfrontend - listfront + 1);
        if(start!=-1) pq.push(end_of_list - start + 1);
        pq.push(n - listback);
        pq.push(listbackend + 1);
        if(start2 != -1 ) pq.push(end_of_start2 - start2 + 1);


        if(listfrontend!=-1 and listfrontend+1==listfront) pq.push(n);

        if (listfrontend+1 == start and listfrontend!=-1) pq.push(end_of_list - listfront + 1);
        if (end_of_list +1 == listback and end_of_list!=-1 ) pq.push(n-start);
        if (listbackend +1 == listfront and listbackend!=-1) pq.push(listfrontend + 1);
        if (listfrontend+1 == start and listbackend +1 == listfront and listfrontend!=-1 and listbackend!=-1) pq.push(end_of_list + 1);
        if (end_of_list +1 == listback and listfrontend+1 == start and end_of_list!=-1 and listfrontend!=-1) pq.push(n-listfront);
        if (listfrontend+1 == start and listbackend +1 == listfront and end_of_list +1 == listback and listfrontend!=-1 and listbackend!=-1 and end_of_list!=-1) pq.push(n);

        if(pq.top() <= k) cout<<pq.top()<<endl;
        else cout<<k<<endl;
        
        
      }

      //case 4  -  {  lfe]...[s2, eo2]...[s, eo1]...[lb , lbe]...[lf  }
      if(listfront > listfrontend and start <= end_of_list and listback <= listbackend)
      {
        if(start!=-1) pq.push(end_of_list - start + 1);
        if(listback != -1) pq.push(listbackend - listback + 1);
        pq.push(listfrontend + 1);
        pq.push(n-listfront);
        if(start2 != -1 ) pq.push(end_of_start2 - start2 + 1);

        
        if(listfrontend!=-1 and listfrontend+1==listfront) pq.push(n);


        if(listfrontend + 1 == start and listfrontend!=-1) pq.push(end_of_list+1);
        if(end_of_list + 1 == listback and end_of_list!=-1) pq.push(listbackend - start + 1);
        if(listbackend+1 == listfront and listbackend!=-1) pq.push(n-listback);
        if(listfrontend + 1 == start and end_of_list + 1 == listback and listfrontend!=-1 and end_of_list!=-1) pq.push(listbackend+1);
        if(end_of_list + 1 == listback and listbackend+1 == listfront and end_of_list!=-1 and listbackend!=-1 ) pq.push(n-start);
        if(listfrontend + 1 == start and end_of_list + 1 == listback and listbackend+1 == listfront and listfrontend!=-1 and end_of_list!=-1) pq.push(n);

        if(pq.top() <= k) cout<<pq.top()<<endl;
        else cout<<k<<endl;

      }

      
    }
    
    
   }

  return 0;
}













