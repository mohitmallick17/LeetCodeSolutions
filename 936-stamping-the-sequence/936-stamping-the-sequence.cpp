class Solution {
    bool stampFound(int start, string &s, string &t){
        for(int i=0;i<s.size();i++){
            if(t[start + i] != '*' and t[start + i] != s[i])return false;
        }
        return true;
    }
    void markStamp(int start, string &s, string &t, int &cnt){
        for(int i=0;i<s.size();i++){
            if(t[start + i] != '*'){
                t[start + i] = '*';
                cnt++;
            }
        }
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        
        int stars = 0;
        vector<bool> visited(target.size(), false);
        
        while(stars < target.size()){
            bool found = false;
            for(int i=0;i<=target.size()-stamp.size();i++){
                if(!visited[i] and stampFound(i, stamp, target)){
                    markStamp(i, stamp, target, stars);
                    found=true;
                    res.push_back(i);
                    visited[i]=true;
                    if(stars==target.size())break;
                }
            }
            if(!found)return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};