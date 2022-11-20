class Solution {
public:
    int calculate(string s) {
        int res=0, cur=0, sign=1;
        stack<int> stk;
        
        for(char &c:s){
            if(c >= '0' && c<= '9')
                cur = (cur*10) + (c - '0');
            else if(c == '+'){
                res += sign*cur;
                sign=1;
                cur=0;
            }else if(c == '-'){
                res += sign*cur;
                sign=-1;
                cur=0;
            }else if(c == '('){
                res += sign*cur;  
                stk.push(res);
                stk.push(sign);
                sign=1;
                res=0;
            }else if(c == ')'){
                res += sign*cur;
                int prev_sign = stk.top();
                stk.pop();
                int prev_res = stk.top();
                stk.pop();
                res = prev_res + prev_sign*res;
                cur = 0;
            }
        }
        if(cur != 0)res += sign*cur;
        
        return res;
    }
};