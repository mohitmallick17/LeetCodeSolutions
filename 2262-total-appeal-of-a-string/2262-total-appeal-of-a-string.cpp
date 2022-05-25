class Solution {
public:
    long long appealSum(string s) {
        vector<int> freq(26, -1);
        long long res=0, prev=0, cur=0;
        
        for(int i=0;i<s.size();i++){
            char ch=s[i]-'a';
            cur = prev + i - freq[ch];
            freq[ch]=i;
            res += cur;
            prev=cur;
        }
        return res;
    }
};