class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<unordered_set<int>>> v(2, vector<unordered_set<int>>(n, unordered_set<int>()));
        for(auto &r:redEdges){
            v[0][r[0]].insert(r[1]);
        }
        for(auto &b:blueEdges){
            v[1][b[0]].insert(b[1]);
        }
        int INF=2*n;
        vector<vector<int>> res(2, vector<int>(n, 0));
        for(int i=1;i<n;i++){
            res[0][i]=INF;
            res[1][i]=INF;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        
        while(!q.empty()){
            int u = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto nbr:v[1-col][u]){
                if(res[1-col][nbr]==INF){
                    res[1-col][nbr] = 1 + res[col][u];
                    q.push({nbr, 1-col});
                }
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int c = min(res[0][i], res[1][i]);
            ans[i] = (c==INF) ? -1:c;
        }
        return ans;
    }
};