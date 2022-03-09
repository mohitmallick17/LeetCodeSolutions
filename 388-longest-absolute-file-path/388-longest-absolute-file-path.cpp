class Solution {
    vector<string> split(string &s){
        vector<string> res;
        stringstream ss(s);
        string cur;
        while(getline(ss, cur)){
            res.push_back(cur);
        }
        return res;
    }
public:
    int lengthLongestPath(string input) {
        vector<string> v = split(input);
        stack<int> stk;
        stk.push(0);
        int maxLen = 0;
        
        for(string s:v){
            int numTabs = s.find_last_of('\t') + 1;
            int level = numTabs + 1;
            
            while(level < stk.size())stk.pop();
            
            int curLen = stk.top() + s.size() - numTabs + 1;
            stk.push(curLen);
            if(s.find('.') != std::string::npos)
                maxLen = max(maxLen, curLen-1);
        }
        return maxLen;
    }
};