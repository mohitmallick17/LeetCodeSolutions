class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        unordered_set<int> open, close;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                stk.push(i);
            else if(s[i] == ')' and !stk.empty()){
                open.insert(stk.top());
                close.insert(i);
                stk.pop();
            }
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i] != '(' and s[i] != ')')
                res += s[i];
            else{
                if(s[i]=='(' and open.find(i) != open.end())
                    res += '(';
                else if(close.find(i) != close.end())
                    res += ')';;
            }
        }
        return res;
    }
};