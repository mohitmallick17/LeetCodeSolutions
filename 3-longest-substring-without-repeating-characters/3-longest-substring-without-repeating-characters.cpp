class Solution {
    int charToIndex(const char &c){
        return c;
    }
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int res = 0;
        for(int end=0, start=0;end<s.size();end++){
            int idx = charToIndex(s[end]);
            freq[idx]++;
            
            while(freq[idx] > 1 and start < end){
                freq[charToIndex(s[start++])]--;
            }
            
            res = max(res, end-start+1);
            
        }
        return res;
    }
};