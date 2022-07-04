class Solution {
    int ans = INT_MAX;
    
    void solve(string start, string &end, unordered_set<string> st, int steps){
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
                if(st.find(ss) != st.end()){
                    st.erase(ss);
                    solve(ss, end, st, steps+1);
                    st.insert(ss);
                }
                ss[i]=cur;
            }
        }
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        solve(start, end, st, 0);
        return ans==INT_MAX?-1:ans;
    }
};