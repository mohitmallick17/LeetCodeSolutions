// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount){
	    vector<int> v(amount+1, INT_MAX);
	    v[0]=0;
	    
        for(int num:nums){
            // cout << num << ": " << '\n';
    	    for(int a=1;a<=amount;a++){
                if(a >= num and v[a-num]!=INT_MAX)
                    v[a] = min(v[a], v[a-num]+1);
                // cout << v[a] << ' ';
            }
            // cout << '\n';
	    }
	    return (v[amount]==INT_MAX ? -1 : v[amount]);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends