class Solution {
    bool isPalin(int low, int high, string &s){
        while(low < high){
            if(s[low] != s[high])
                return false;
            low++, high--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l=0, h=s.size()-1;
        
        while(l < h){
            if(s[l] != s[h]){
                return isPalin(l, h-1, s) or isPalin(l+1, h, s);
            }
            l++, h--;
        }
        return true;
    }
};