// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int traverse(vector<vector<int>> &mat,int i,int 
    		j,vector<vector<int>> &dp,int &ans){
    if(dp[i][j]!=0) return dp[i][j];
    int n=mat.size(),m=mat[0].size();
    int a1[]={-1,1,0,0};
    int a2[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int a=i+a1[k],b=j+a2[k];
        if(a>=0&&a<n&&b>=0&&b<m){
          if(mat[a][b]>mat[i][j])
           dp[i][j]=max(dp[i][j],
              1+traverse(mat,a,b,dp,ans));
        }
    }
    ans=max(ans,dp[i][j]);
    return dp[i][j];
}
int longestIncreasingPath(vector<vector<int>>& mat) {
    int ans=0,n=mat.size(),m=mat[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dp[i][j]==0)
            traverse(mat,i,j,dp,ans);
        }
    }
    return ans+1;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends