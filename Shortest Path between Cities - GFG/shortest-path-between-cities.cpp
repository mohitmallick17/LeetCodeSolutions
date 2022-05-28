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
        if(x==y)return 0;
        // code here 
        int lc=0, rc=0;
        
        while(x != y){
            if(x > y){
                x = getPar(x);
                lc++;
            }
            else{
                y = getPar(y); 
                rc++;
            }
        }
        return lc+rc;
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