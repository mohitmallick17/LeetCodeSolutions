// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string S){
        int i=S.size()-2;
        while(i >= 0 and S[i+1] >= S[i])
            i--;
        if(i==-1)return "-1";
        
        char prev = 1;
        int previ = -1;
        for(int j=S.size()-1;j>i;j--){
            if(S[i] > S[j] and prev <= S[j]){
                prev = S[j];
                previ=j;
            }
        }
        if(prev=='0' and i==0)return "-1";
        swap(S[i], S[previ]);
        return S;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends