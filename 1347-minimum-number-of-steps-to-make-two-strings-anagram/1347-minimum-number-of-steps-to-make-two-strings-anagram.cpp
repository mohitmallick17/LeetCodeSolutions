class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sc(26, 0), tc(26, 0);
        for(char &c:s)
            sc[c-'a']++;
        for(char &c:t)
            tc[c-'a']++;
        
        int count = 0;
        for(int i=0;i<26;i++){
            count += max((tc[i] - sc[i]), 0);
        }
        return count;
    }
};