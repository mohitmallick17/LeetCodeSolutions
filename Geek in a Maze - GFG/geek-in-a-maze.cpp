// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int m, int n, int r, int c, int u, int d, vector<vector<char>> &mat){
	    if(mat[r][c] == '#')return 0;
	    queue<vector<int>> q;
	    q.push({r, c, 0, 0});
	    int res = 1;
	    mat[r][c]='*';
	    
	    while(!q.empty()){
	        auto v = q.front();
	        int i=v[0], j=v[1], uu=v[2], dd=v[3];
	        q.pop();
	        // left
	        if(j-1>=0 and mat[i][j-1]=='.'){
	            q.push({i, j-1, uu, dd});
	            mat[i][j-1]='*';
    	        res++;
	        }
	        // right
	        if(j+1<n and mat[i][j+1]=='.'){
	            q.push({i, j+1, uu, dd});
        	    mat[i][j+1]='*';
    	        res++;
	        }
	        // up
	        if(i-1>=0 and uu<u and mat[i-1][j]=='.'){
	            q.push({i-1, j, uu+1, dd});
	            mat[i-1][j]='*';
    	        res++;
	        }
	        // down
	        if(i+1<m and dd<d and mat[i+1][j]=='.'){
	            q.push({i+1, j, uu, dd+1});
	            mat[i+1][j]='*';
    	        res++;
	        }
	    }
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
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends