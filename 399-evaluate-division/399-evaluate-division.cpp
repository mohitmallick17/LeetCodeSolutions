class Solution {
    unordered_map<string, vector<pair<string, double>>> buildG(vector<vector<string>>& eq, vector<double>& val){
        unordered_map<string, vector<pair<string, double>>> g;
        for(int i=0;i<val.size();i++){
            string src=eq[i][0], dst=eq[i][1];
            double cost = val[i];
            
            g[src].push_back({dst, cost});
            g[dst].push_back({src, 1/cost});
        }
        return g;
    }
    double dfs(string &src, string &dst, unordered_map<string, vector<pair<string, double>>> &g, unordered_set<string> &vis){
        
        if(g.find(src)==g.end() or g.find(dst)==g.end())return -1.0;
        if(src==dst)return 1.0;
        vis.insert(src);
        
        for(auto &x:g[src]){
            string nbr=x.first;
            double wt=x.second;
            if(vis.find(nbr)!=vis.end())continue;
            double res=dfs(nbr,dst,g,vis);
            if(res != -1)return wt*res;
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto graph = buildG(equations, values);    
        
        vector<double> res;
        for(auto &q:queries){
            unordered_set<string> vis;
            double val = dfs(q[0], q[1], graph, vis);
            res.push_back(val);
        }
        return res;
    }
};