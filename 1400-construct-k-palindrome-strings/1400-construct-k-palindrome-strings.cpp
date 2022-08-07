class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k)return false;
        vector<int> cnt(26, 0);
        
        for(char &c:s)cnt[c-'a']++;
        
        int odds=0;
        for(int i=0;i<26;i++){
            if(cnt[i] & 1)odds++;
            if(odds > k)return false;
        }
        return true;
    }
};