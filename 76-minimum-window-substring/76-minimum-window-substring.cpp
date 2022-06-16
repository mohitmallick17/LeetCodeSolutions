class Solution {
    bool isSubset(vector<int> &a, vector<int> &b){
        for(int i=0;i<256;i++){
            if(b[i] > a[i])return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> hs(256, 0), ht(256, 0);
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