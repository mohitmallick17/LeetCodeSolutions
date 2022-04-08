class Solution {
    void dfs(string start,  unordered_map<string, multiset<string>> &g, stack<string> &stk){
        while(!g[start].empty()){
            string nbr = *(g[start].begin());
            g[start].erase(g[start].find(nbr));
            dfs(nbr, g, stk);
        }
        stk.push(start);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // create graph, but all adjacent nodes have to be sorted (to create smallest possible ans)
        unordered_map<string, multiset<string>> mp;
        for(auto &t:tickets)
            mp[t[0]].insert(t[1]);
        stack<string> stk;
        
        dfs("JFK", mp, stk);
        
        vector<string> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};