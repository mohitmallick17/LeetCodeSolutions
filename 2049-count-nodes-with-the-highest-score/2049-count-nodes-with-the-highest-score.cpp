class Solution {    
    long long ans=0;
    long long h=0;
    
    int solve(int node,unordered_map<int, unordered_set<int>> &p2c, int n){
        long long cur_size = 1;
        long long p = 1;
        
        for(auto &ch:p2c[node]){
            int val = solve(ch, p2c, n);
            cur_size += val;
            p *= val;
        }
        if(node != 0)
            p *= (n - cur_size);
        
        if(p > h)h=p, ans=1;
        else if(h==p)ans++;
        
        return cur_size;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        
        unordered_map<int, unordered_set<int>> p2c;
        for(int i=1;i<parents.size();i++){
            int c=i, p=parents[i];
            p2c[p].insert(c);
        }
        solve(0, p2c, n);
        return ans;
    }
};