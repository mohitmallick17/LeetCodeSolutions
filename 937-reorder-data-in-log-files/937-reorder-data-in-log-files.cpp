class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dl, ans;
        vector<pair<string, string>> ll;
        for(string &log:logs){
            int idx = log.find(' ');
            if(isalpha(log[idx+1])){
                ll.emplace_back(log.substr(0, idx), log.substr(idx + 1));
            }else
                dl.push_back(log);            
        }
        sort(ll.begin(), ll.end(), [&](auto &a, auto &b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;    
        });
        
        for(auto &x:ll){
            ans.push_back(x.first + " " + x.second);    
        }
        for(auto &x:dl)ans.push_back(x);
        return ans;
    }
};