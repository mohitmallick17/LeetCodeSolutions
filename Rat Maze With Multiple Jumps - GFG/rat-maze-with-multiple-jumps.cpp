// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
//     int solve(int i, int j, vector<vector<int>> &g, vector<vector<int>> &res, int m, int n){
//         if(i>=m or j>=n or or g[i][j]==0)return INT_MAX;
        
//         res[i][j]=1;
        
//         bool found=false;
//         int cost=INT_MAX;
        
//         for(int x=i;x<min(i+g[i][j], m);x++){
//             for(int y=i;x<min(j+g[i][j], n);y++){
//                 int val = solve(x, y, g, res, m,n );
//                 if(val != INT_MAX){
//                     found=true;
//                     cost = min(cost, val);
//                 }
//             }    
//         }
//         if(!found){
//             res[i][j]=0;
//             return INT_MAX;
//         }
//         return cost+1;
//     }
// public:
//     bool isSafe(vector<vector<int>> &matrix, int x, int y){
//         if(x>=matrix.size() || y>=matrix[0].size() || matrix[x][y]==0){
//             return false;
//         }
//         return true;
// }
public:
bool isSafe(vector<vector<int>> &matrix, int x, int y){
        if(x>=matrix.size() || y>=matrix[0].size() || matrix[x][y]==0){
            return false;
        }
        return true;
}
bool helper(vector<vector<int>> &matrix, vector<vector<int>> &res, int x, int y, int n){
        if(x==n-1 && y==n-1){
            res[x][y]=1;
            return true;
        }
        if(isSafe(matrix,x,y)==true){
            res[x][y]=1;
            for(int i=1;i<=matrix[x][y] && i<n;i++){
                if(helper(matrix,res,x,y+i,n)==true){
                    return true;
                }
                if(helper(matrix,res,x+i,y,n)==true){
                    return true;
                }
            }
            res[x][y]=0;
            return false;
        }
        return false;
}
vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix){
	    int n=matrix.size();
	    if(matrix[0][0]==0 && n!=1){
	        return {{-1}};
	    }
	    vector<vector<int>> res(n,vector<int>(n,0));
	    helper(matrix,res,0,0,n);
	    return res;
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