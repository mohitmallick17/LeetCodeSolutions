class Solution {
    int ans = INT_MAX;
    
    void solve(string start, string &end, unordered_set<string> st, int steps, unordered_set<string>& vis){
        if(start==end){
            ans = min(ans, steps);
            return;
        }
        
        for(int i=0;i<8;i++){
            char cur = start[i];
            string ss=start;
            for(const char &nw:"ACGT"){
                if(cur==nw)continue;
                ss[i]=nw;
                if(st.find(ss) != st.end() and vis.find(ss)==vis.end()){
                    vis.insert(start);
                    solve(ss, end, st, steps+1, vis);
                    vis.erase(start);
                }
                ss[i]=cur;
            }
        }
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end()), vis;
        solve(start, end, st, 0, vis);
        return ans==INT_MAX?-1:ans;
    }
};