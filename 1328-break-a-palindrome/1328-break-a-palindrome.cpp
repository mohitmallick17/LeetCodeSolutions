class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i] != 'a'){
                s[i]='a';
                return s;
            }
        }
        if(n>1){
            s.back()='b';
            return s;
        }
        return "";
    }
};