class Solution {
    vector<int> getCnt(string &s){
        vector<int> v(26, 0);
        for(char &c:s)v[c-'a']++;
        return v;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> cur(26, 0);
        
        for(auto &b:words2){
            auto w = getCnt(b);
            for(int i=0;i<26;i++)cur[i]=max(cur[i], w[i]);
        }
        
        vector<string> res;
        for(auto &a:words1){
            auto w = getCnt(a);
            int i;
            for(i=0;i<26;i++){
                if(w[i] < cur[i])break;
            }
            if(i==26)res.push_back(a);
        }
        return res;
    }
};

// b[i] <= a[i] (cnt)