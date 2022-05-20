// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B){
        if(A.size() != B.size())return -1;
        
        unordered_map<char, int> ma, mb;
        for(char &c:A)ma[c]++;
        for(char &c:B)mb[c]++;
        if(ma != mb)return -1;
        int cost=0;
        for(int i=A.size()-1, j=B.size()-1;i>=0;i--){
            if(A[i]==B[j])j--;
            else{
                cost++;
            }
        }
        return cost;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends