// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int bitA=0;
        int bitB=0;
    int A=a;
    int B=b;
    
    while(A>0){
        if(A%2==1)bitA++;
        A>>=1;
    }
    while(B>0){
        if(B%2==1)bitB++;
        B>>=1;
    }
    
    if(bitA>bitB){
     int make=1;  
     int count=bitA-bitB;
        while(count>0){
            if((make&a)!=0){
                a^=make;
                count--;
            }
            make<<=1;
        }
        return a;
        
    }else if(bitA<bitB){
        int make=1;
        int turn=bitB-bitA;
        while(turn>0){
            if((a&make)==0){
                a^=make;
                turn--;
            }
            make<<=1;
        }
        return a;
        
    }else{
        return a;
    }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends