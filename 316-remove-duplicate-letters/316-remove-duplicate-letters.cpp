class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        stack<char> stk;
        for(const char& c:s)
            freq[c-'a']++;
        for(const char& c:s){
            freq[c-'a']--;
            if(visited[c-'a'])continue;
            
            while(!stk.empty() and stk.top() > c and freq[stk.top()-'a'] > 0){
                visited[stk.top()-'a']=false;
                stk.pop();
            }
            stk.push(c);
            visited[c-'a']=true;
        }
        string res;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};