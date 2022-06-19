class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk;
        string cur;
        
        for(const char &c:s){
            if(c=='('){
                if(!cur.empty()){
                    stk.push_back(cur);
                    cur.clear();
                }
                stk.push_back("(");
            }else if(c==')'){
                reverse(cur.begin(), cur.end());
                while(stk.back() != "("){
                    reverse(stk.back().begin(), stk.back().end());
                    cur += stk.back();
                    stk.pop_back();
                }
                stk.pop_back();
                if(cur.empty())continue;
                stk.push_back(cur);
                cur.clear();
            }else{
                cur += c;
            }
        }
        if(!cur.empty())stk.push_back(cur);
        cur.clear();
        for(int i=0;i<stk.size();i++)cur+=stk[i];
        return cur;
    }
};