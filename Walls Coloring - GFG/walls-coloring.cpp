//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        // colors[3][i] = {cost of r, cost of g, cost of b} for the ith wall
        vector<vector<int>> cost(n, vector<int>(3));
        // cost[x][i] minimum total cost of from 0th wall till ith wall, such that
        // we pick color x for painting the ith wall
        
        cost[0][0]=colors[0][0];
        cost[0][1]=colors[0][1];
        cost[0][2]=colors[0][2];
        
        for(int i=1;i<n;i++){
            for(int c=0;c<3;c++){
                int c2,c3;
                if(c==0)c2=1,c3=2;
                else if(c==1)c2=0,c3=2;
                else if(c==2)c2=0,c3=1;
                cost[i][c] = colors[i][c] + min(cost[i-1][c2], cost[i-1][c3]);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout << cost[i][0] << ' ' << cost[i][1] << ' ' << cost[i][2] << '\n';
        // }
        return min({cost.back()[0], cost.back()[1], cost.back()[2]});
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends