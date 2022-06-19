class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0, open=0, close=0;
        for(char &c:s){
            if(c=='(')open++;
            else close++;
            
            if(close > open){
                cnt++;
                open=close=0;
            }
        }
        cnt += (open-close);
        return cnt;
    }
};