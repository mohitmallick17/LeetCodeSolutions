class DSU{
    vector<int> v;
    vector<int> rank;
public:
    DSU(int size){
        v.resize(size);
        rank.resize(size,1);
        for(int i=0;i<size;i++)v[i]=i;
    }
    int findPar(int k){
        if(k==v[k])return k;
        return v[k]=findPar(v[k]);
    }
    void union_(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa==pb)return;
        if(rank[pa] > rank[pb]){
            v[pb]=pa;
        }else if(rank[pa] < rank[pb]){
            v[pa]=pb;
        }else{
            v[pb]=pa;
            rank[pa]++;
        }
    }
    bool isSibling(int a, int b){
        return findPar(a)==findPar(b);
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> adj[n];
        for(auto &x:edges){
            int s=x[0], d=x[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        // key: value, val: index of nodes
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
            mp[vals[i]].push_back(i);
        
        DSU dsu(n);
        
        int ans = n;
        vector<int> vis(n, false);
        
        for(auto &[val,indexes]:mp){
            unordered_map<int,int> cnt;
            for(auto &idx:indexes){
                for(auto &nbr:adj[idx]){
                    if(vis[nbr])dsu.union_(idx, nbr);
                }
                vis[idx]=true;
            }
            for(auto &idx:indexes)
                cnt[dsu.findPar(idx)]++;
            for(auto &[k,v]:cnt){
                if(v >= 2)ans += ((v)*(v-1))/2;
            }
        }
        return ans;
    }
};