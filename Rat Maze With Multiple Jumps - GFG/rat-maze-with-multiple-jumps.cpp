// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool solve(int i, int j, vector<vector<int>>&g, vector<vector<int>>&ans){
        int n=g.size();
        
        if(i>=n or j>=n)return false;
        ans[i][j]=1;
        if(i==n-1 and j==n-1)return true;
        
        for(int jumps=1;jumps<=g[i][j];jumps++){
            // forward
            if(solve(i, j+jumps, g, ans))return true;
            // downwards
            if(solve(i+jumps, j, g, ans))return true;
        }
        // backtrack
        ans[i][j]=0;
        return false;
    }
    
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>>&g){
	   int n=g.size();
	   vector<vector<int>> ans(n, vector<int>(n, 0));
	   if(solve(0,0,g,ans))return ans;
	   return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends