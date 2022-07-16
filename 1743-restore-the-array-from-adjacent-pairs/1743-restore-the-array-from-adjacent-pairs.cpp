class Solution {
    vector<int> ans;
    void dfs(int num, int par, unordered_map<int, unordered_set<int>>& adj){
        // if(adj[num].empty())return;
        ans.push_back(num);
        
        for(auto &nbr:adj[num]){
            if(nbr != par)
                dfs(nbr, num, adj);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, unordered_set<int>> hash;
        for(auto &x:adjacentPairs){
            hash[x[0]].insert(x[1]);
            hash[x[1]].insert(x[0]);
        }
        for(auto &x:hash){
            if(x.second.size()==1){
                dfs(x.first, -1e9, hash);
                return ans;
            } 
        }
        return {};
    }
};