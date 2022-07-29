class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string &cur:words){
            if(cur.size() != pattern.size())continue;
            int i;
            unordered_map<char, char> p2w;
            vector<bool> reserved(26, false);
            for(i=0;i<cur.size();i++){
                if(p2w.find(pattern[i])==p2w.end()){
                    if(reserved[cur[i]-'a'])break;
                    p2w[pattern[i]]=cur[i];
                    reserved[cur[i]-'a']=true;
                }
                else if(p2w[pattern[i]] != cur[i])
                    break;
            }
            if(i==cur.size())res.push_back(cur);
        }
        return res;
    }
};