// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        // int c=0;
        // int res=0;
        // for(int i=0;i<32;i++){
        //     int x=(a>>i)&1;
        //     int y=(b>>i)&1;
        //     if(x+y+carry > 1)
        // }
        
       int carry = 0;
       while(b && 1){
           carry = a & b;
           a = a ^ b;
           b = carry << 1;
       }
       return a;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends