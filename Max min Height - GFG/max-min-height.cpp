//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    bool isValid(vector <int> a, int n, int k, int w, int minVal){
        for(int i=0;i<n;i++){
            if(a[i] < minVal){
                int cnt = minVal-a[i];
                if(cnt > k)return false;
                k -= cnt;
                for(int j=i;j<min(n, i+w);j++)
                    a[j] += cnt;
            }
        }
        return true;
    }
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a){
            long long low = *min_element(a.begin(), a.end());
            long long high = low+k;
            
            long long ans=low;
            
            while(low <= high){
                long long mid = low + (high-low)/2;
                
                if(isValid(a,n,k,w,mid)){
                    ans=mid;
                    low=mid+1;
                }else
                    high=mid-1;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends