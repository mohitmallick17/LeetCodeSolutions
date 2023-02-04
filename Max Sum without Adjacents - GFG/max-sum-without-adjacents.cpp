//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *v, int n) {
	   // if(n==1)return v[0];
	   // if(n==2)return max(v[0], v[1]);

	   // v[2] += v[0];
	   // int ans = max(v[2], v[1]);
	   // if(n==3)return ans;
	    
	   // 1 100 10 4
	   int ans = v[0];//max(v[0], v[1]);
	    for(int i=1;i<n;i++){
	        v[i] = max(v[i-1], v[i] + v[i-2]);
	        ans = max(ans, v[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends