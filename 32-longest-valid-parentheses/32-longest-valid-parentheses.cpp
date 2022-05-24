class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0, close=0, res=0;
        for(char &c:s){
            if(c=='(')open++;
            else close++;
            
            if(close > open)close=open=0;
            else if(open==close) res = max(res, close+open);
        }
        open=close=0;
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            if(c=='(')open++;
            else close++;
            
            if(open>close)close=open=0;
            else if(open==close) res = max(res, close+open);
        }
        return res;
    }
};