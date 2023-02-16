//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dirs[] = {0,1,0,-1,0};
class Solution{
    void dfs(int i, int j, vector<vector<bool>> &v, int m, int n, vector<vector<int>> &mat, int height){
        if(i<0 or j<0 or i==m or j==n or v[i][j] or mat[i][j] < height)return;
        v[i][j]=true;
        for(int d=0;d<4;d++){
            dfs(i+dirs[d], j+dirs[d+1], v, m, n, mat, mat[i][j]);
        }
    }
public:
    int water_flow(vector<vector<int>> &mat,int m,int n){
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            dfs(i, 0, pacific, m, n,mat,mat[i][0]);
            dfs(i, n-1, atlantic, m, n,mat,mat[i][n-1]);
        }
        for(int i=0;i<n;i++){
            dfs(0, i, pacific, m, n,mat,mat[0][i]);
            dfs(m-1, i, atlantic, m, n,mat,mat[m-1][i]);
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])res++;
            }
        }
        return res;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends