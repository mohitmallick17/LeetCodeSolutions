// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<vector<int>> res;
    void solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<int>& cur){
        cur.push_back(grid[i][j]);
        if(i==m-1 and j==n-1){
            res.push_back(cur);
            cur.pop_back();
            return;
        }
        if(i+1 < m)solve(i+1, j, m, n, grid, cur);
        if(j+1 < n)solve(i, j+1, m, n, grid, cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
        vector<int> tmp;
        solve(0,0,grid.size(), grid[0].size(), grid, tmp);
        return res;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends