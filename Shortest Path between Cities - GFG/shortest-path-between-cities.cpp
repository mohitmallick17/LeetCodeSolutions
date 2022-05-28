// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{  
    int getPar(int c){
        if(c==1)return 1;
        return c/2;
    }
public:
    int shortestPath( int x, int y){ 
        int count=0;
       while(x!=y){
           if(x>y)
           x/=2;
           
           else if(y>x)
           y/=2;
           
           count++;
       }
       return count;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends