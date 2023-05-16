//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long convertBinarytoDecimal(string &str){
        long long decimal=0;
        long long base=1;
        int size=str.size();
        for(int i=size-1;i>=0;i--){
            if(str[i]=='1')
                decimal+=base;
            base*=2;
        }
        return decimal;
    }
    int cuts(string s){
        int n=s.size();
        if(n==0 || s[0]=='0' || s[n-1]=='0')
            return -1;
        if(ceil(log2(convertBinarytoDecimal(s))/log2(5))==floor(log2(convertBinarytoDecimal(s))/log2(5)))
            return 1;
        int minCuts=INT_MAX;
        for(int i=1;i<n;i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            if(ceil(log2(convertBinarytoDecimal(left))/log2(5))==floor(log2(convertBinarytoDecimal(left))/log2(5))){
                int cutsRight=cuts(right);
                if(cutsRight!=-1)
                    minCuts=min(minCuts,1+cutsRight);
            }
        }
        if(minCuts==INT_MAX)
            return -1;
        return minCuts;
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends