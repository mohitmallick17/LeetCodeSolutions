class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res=0;
        stk.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            }else{
                if(!stk.empty())stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    int len = i-stk.top();
                    res = max(res, len);
                }
            }
        }
        return res;
    }
};