class Solution {
    void sortStr(string &s){
        vector<int> cnt(26, 0);
        for(char &c:s)cnt[c-'a']++;
        for(int i=25, p=0;i>=0;i--){
            while(cnt[i]--)s[p++]='a'+i;
        }
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        sortStr(s1);
        sortStr(s2);
        // cout << s1 << ' ' << s2 << '\n';
        int res = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] > s2[i]){
                if(res>=0)res=1;
                else return false;
            }else if(s2[i] > s1[i]){
                if(res <= 0)res=-1;
                else return false;
            }
        }
        return true;
    }
};