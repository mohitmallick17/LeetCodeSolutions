class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk;
        string cur;
        int n=s.size();
        int lo=0, hi=n-1;
//         while(lo<n and s[lo]!='(')lo++;
//         while(hi>=lo and s[hi]!=')')hi--;
//         if(lo > hi)return s;
        
        for(int i=lo;i<=hi;i++){
            char c=s[i];
            if(c=='('){
                if(!cur.empty()){
                    stk.push_back(cur);
                    cur="";
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
                cur="";
            }else{
                cur += c;
            }
        }
        if(cur.size() > 0)stk.push_back(cur);
        cur="";
        // while(!stk.empty()){
        //     cur += stk.top();
        //     stk.pop();
        // }
        // return s.substr(0, lo) + cur + s.substr(hi+1);
        for(int i=0;i<stk.size();i++)cur+=stk[i];
        return cur;
    }
};