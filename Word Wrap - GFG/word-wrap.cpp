// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    int ans;
    void solve(int i, vector<int> &nums, int cost, int k, int ok){
        cout << i << ' ' << nums[i] << ' ' << k << ' ' << cost << '\n';
        if(i==nums.size()){
            ans = min(ans, cost);
            return;
        }
        if(nums[i] <= k){
            // pick
            solve(i+1, nums, cost, k-nums[i]-(k != ok), ok);
            // not pick, if not the first item
            if(k != ok)
                solve(i+1, nums, cost+(k*k), ok-nums[i], ok);
        }else{
            // not pick
            solve(i+1, nums, cost+(k*k), ok-nums[i], ok);
        }
    }
public:
    int solveWordWrap(vector<int> &nums, int k){
        // ans = INT_MAX;
        // solve(0, nums, 0, k, k);
        // return ans;
          int n = nums.size();
       int inf = INT_MAX;
       int space[n][n];
       for(int i=0; i<n; i++){
           space[i][i] = k - nums[i];
           for(int j=i+1; j<n; j++){
               space[i][j] = space[i][j-1] - nums[j] - 1;
           }
       }
       
       int cost[n][n];
       for(int i=0; i<n; i++){
           for(int j=i; j<n; j++){
               if(space[i][j] < 0) cost[i][j] = inf;
               else{
                   if(j == n-1) cost[i][j] = 0;
                   else cost[i][j] = space[i][j] * space[i][j]; 
               }
           }
       }
       
       int min_cost[n];
       for(int i=n-1; i>=0; i--){
           min_cost[i] = cost[i][n-1];
           for(int j=n-1; j>i; j--){
               if(cost[i][j-1] == inf) continue;
               if(cost[i][j-1] + min_cost[j] < min_cost[i]){
                   min_cost[i] = cost[i][j-1] + min_cost[j];
               }
           }
       }
       
       return (min_cost[0]);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends