class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26), b(26);
        for(char &c:word1)a[c-'a']++;
        for(char &c:word2)b[c-'a']++;
        
        for(int i=0;i<26;i++){
            if(a[i]==0 ^ b[i]==0)return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        return a==b;
    }
};