class Solution {
    bool isDigit(char &c){
        return (c>='0' and c<='9');
    }
public:
    int calculate(string s) {
        long long Sum=0, sign=+1;
        stack<long long> stk;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isDigit(s[i])){
                long long val = 0;
                while(i<n and isDigit(s[i])){
                    val = (val*10) + s[i]-'0';
                    i++;
                }
                i--;
                val *= sign;
                Sum += val;
                sign=+1;
            }else if(s[i]=='-'){
                sign *= -1;
            }else if(s[i]=='('){
                stk.push(Sum);
                stk.push(sign);
                Sum=0;
                sign=+1;
            }else if(s[i]==')'){
                Sum *= stk.top(); // sign
                stk.pop();
                Sum += stk.top();
                stk.pop();
            }
        }
        return Sum;
    }
};