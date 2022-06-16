class Solution {
    bool isSubset(unordered_map<char, int> &a, unordered_map<char, int> &b){
        for(auto &x:b){
            if(a[x.first] < x.second)return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for(char &c:t)ht[c]++;
        
        string res;
        for(int start=0, end=0;end<s.size();end++){
            hs[s[end]]++;
            
            while(start<=end and isSubset(hs,ht)){
                if(res.empty() or res.size() > end-start+1)
                    res = s.substr(start, end-start+1);
                if(start==end)break;
                hs[s[start]]--;
                start++;
            }
        }
        return res;
    }
};