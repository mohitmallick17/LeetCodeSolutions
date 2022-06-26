// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n){
        unordered_set<int> st;
        for(int i=0;i<n;i++)st.insert(arr[i]);
        
        int distinct = st.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for(int start=0, end=0;end<n;end++){
            mp[arr[end]]++;
            while(start <= end and mp.size() >= distinct){
                ans += n-end;
                mp[arr[start]]--;
                if(mp[arr[start]]==0)mp.erase(arr[start]);
                start++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends