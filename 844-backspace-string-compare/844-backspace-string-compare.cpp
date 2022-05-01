class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> vs, vt;
        for(char &c:s){
            if(c=='#'){
                if(!vs.empty())vs.pop_back();
            }else
                vs.push_back(c);
        }
        for(char &c:t){
            if(c=='#'){
                if(!vt.empty())vt.pop_back();
            }else
                vt.push_back(c);
        }
        return vs==vt;
    }
};