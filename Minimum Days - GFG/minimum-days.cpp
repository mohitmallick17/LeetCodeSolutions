//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string s, vector<int> &p) {
        int cnt=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])cnt++;
        }
        int i;
        for(i=0;i<n and cnt>0;i++){
            int reduce=0;
            if(p[i]>0 and s[p[i]] == s[p[i]-1])reduce++;
            if(p[i]<n-1 and s[p[i]] == s[p[i]+1])reduce++;
            cnt-=reduce;
            // cout << i << ' ' <<reduce << '\n';
            s[p[i]]='?';
        }
        return i;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends