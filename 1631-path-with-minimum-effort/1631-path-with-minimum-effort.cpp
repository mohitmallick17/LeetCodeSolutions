class cmp{
public:
    bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
        return a.first > b.first;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> c(m, vector<int>(n, INT_MAX));
        c[0][0]=0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> q;
        q.push({0, {0, 0}});
        
        while(!q.empty()){
            auto front=q.top();
            q.pop();
            int i=front.second.first, j=front.second.second;
            
            if(i==m-1 and j==n-1)continue;
            
            if(i+1 < m and c[i+1][j] > max(c[i][j],abs(heights[i+1][j]-heights[i][j]))){
                c[i+1][j] = max(c[i][j],abs(heights[i+1][j]-heights[i][j]));
                q.push({c[i+1][j], {i+1, j}});
            }
            if(j+1 < n and c[i][j+1] > max(c[i][j],abs(heights[i][j+1]-heights[i][j]))){
                c[i][j+1] = max(c[i][j],abs(heights[i][j+1]-heights[i][j]));
                q.push({c[i][j+1], {i, j+1}});
            }
            
            
            if(i-1 >= 0 and c[i-1][j] > max(c[i][j],abs(heights[i-1][j]-heights[i][j]))){
                c[i-1][j] = max(c[i][j],abs(heights[i-1][j]-heights[i][j]));
                q.push({c[i-1][j], {i-1, j}});
            }
            if(j-1 >= 0 and c[i][j-1] > max(c[i][j],abs(heights[i][j-1]-heights[i][j]))){
                c[i][j-1] = max(c[i][j],abs(heights[i][j-1]-heights[i][j]));
                q.push({c[i][j-1], {i, j-1}});
            }
            
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout << c[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        return c[m-1][n-1];
    }
};