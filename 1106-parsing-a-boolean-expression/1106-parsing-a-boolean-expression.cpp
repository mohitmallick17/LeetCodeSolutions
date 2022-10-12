class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for(char &c:expression){
            if(c == ')'){
                unordered_set<char> s;
                while(stk.top() != '('){
                    s.insert(stk.top());
                    stk.pop();
                }
                stk.pop(); // pop (
                char op=stk.top();
                stk.pop(); // pop operator
                if(op=='&'){
                    stk.push((s.find('f') != s.end()) ? 'f' : 't');
                }else if(op=='|'){
                    stk.push((s.find('t') != s.end()) ? 't' : 'f');
                }else{ // op = !
                    stk.push((s.find('t') != s.end()) ? 'f' : 't');                    
                }
            }else if(c != ',')
                stk.push(c);
        }
        return stk.top() == 't';
    }
};