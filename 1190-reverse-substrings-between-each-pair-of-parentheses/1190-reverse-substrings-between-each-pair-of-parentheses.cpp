class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        vector<int> stk, index_mp(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push_back(i);
            }else if(s[i]==')'){
                int start = stk.back();
                stk.pop_back();
                int end = i;
                index_mp[start]=end;
                index_mp[end]=start;
            }
        }
        string res;
        
        for(int i=0, d=1;i<n;i+=d){
            if(s[i] =='(' or s[i]==')')
                i=index_mp[i], d=-d;
            else
                res += s[i];
        }
        return res;
    }
};