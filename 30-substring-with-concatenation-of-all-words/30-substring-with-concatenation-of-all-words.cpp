class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for(auto &w:words)cnt[w]++;
        int sz=s.size(), n=words.size();
        int w=words[0].size();
        vector<int> res;
        for(int i=0;i<sz-(n*w)+1;i++){
            unordered_map<string, int> cur;
            int j=0;
            for(;j<n;j++){
                string key = s.substr(i + j*w, w);
                if(cnt.find(key) != cnt.end()){                
                    cur[key]++;
                    if(cur[key] > cnt[key])break;
                }else
                    break;                
            }
            if(j==n)res.push_back(i);
        }
        return res;
    }
};