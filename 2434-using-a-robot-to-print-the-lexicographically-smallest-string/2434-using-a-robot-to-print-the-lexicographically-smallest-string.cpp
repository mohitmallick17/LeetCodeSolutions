class Solution {
    char getSmallest(vector<int> &freq){
        for(int i=0;i<26;i++){
            if(freq[i])return 'a'+i;
        }
        return 'z';
    }
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for(char &c:s)freq[c-'a']++;
        
        stack<char> stk;
        string res;
        for(char &c:s){
            stk.push(c);
            freq[c-'a']--;
            
            while(!stk.empty() && stk.top() <= getSmallest(freq)){
                res += stk.top();
                stk.pop();
            }
        }
        return res;
    }
};