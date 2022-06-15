class Solution {
    int mostFreqentChCount(vector<int> &cnt){
        return *max_element(cnt.begin(), cnt.end());
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int res=0;
        for(int start=0, end=0;end<s.size();end++){
            cnt[s[end]-'A']++;
            
            while(start < end and (end-start+1)-mostFreqentChCount(cnt) > k){
                cnt[s[start]-'A']--;
                start++;
            }
            
            res = max(res, end-start+1);
        }
        return res;
    }
};