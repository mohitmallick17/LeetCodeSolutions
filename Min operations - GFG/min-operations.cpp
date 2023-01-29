//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        if(a==b)return 0;
        bool f1=true, f2=true;
        for(int i=0;i<32;i++){
            int bit_a = (a>>i)&1;
            int bit_b = (b>>i)&1;
            if(bit_a ^ bit_b){
                if(bit_a)f1=false;
                else f2=false;
            }
        }
        if(f1 or f2)return 1;
        return 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends