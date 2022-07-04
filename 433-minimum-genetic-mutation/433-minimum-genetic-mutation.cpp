class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue<string> q;
        q.push(start);
        int level = 0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string cur = q.front();
                q.pop();
                if(cur==end)return level;
                for(int i=0;i<8;i++){
                    char orig = cur[i];
                    for(const char &mod:"ACGT"){
                        if(orig==mod)continue;
                        cur[i]=mod;
                        if(st.count(cur) == 0)continue; // does not exists in bank
                        q.push(cur); // insert to queue
                        st.erase(cur); // remove from bank(visited)
                    }
                    cur[i]=orig; // revert back to orig char
                }
            }
            level++;
        }
        return -1;
    }
};