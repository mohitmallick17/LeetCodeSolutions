class Solution {
public:
    int scoreOfParentheses(string s) {
        int res = 0;
        int height = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                height++;
            else
                height--;
            
            if(s[i] == ')' and s[i-1]=='(')
                res += (1 << height);
        }
        return res;
    }
};