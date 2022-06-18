// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int x, int y, int xd, int yd, vector<vector<int>> &matrix, int dist, int &ans){
        if(x<0 or y<0 or x==matrix.size() or y==matrix[0].size() or matrix[x][y]!=1)return;
        if(x==xd and y==yd){
            ans = max(ans, dist);
            return;
        }
        matrix[x][y]=2; // mark node as visited
        int dirs[] = {0,1,0,-1,0};
        for(int d=0;d<4;d++){
            int i=x+dirs[d];
            int j=y+dirs[d+1];
            dfs(i,j,xd,yd,matrix,dist+1,ans);
        }
        // backtrack
        matrix[x][y]=1;
    }
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd){
        int ans = -1;
        dfs(xs,ys,xd,yd,matrix,0,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends