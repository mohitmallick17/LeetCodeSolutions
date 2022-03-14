class Solution{
public:
    string simplifyPath(string path){
        vector<string> stk;
        string cur;
        path += '/';
        for(char &c:path){
            if(c=='/'){
                if(cur == ".."){
                    if(!stk.empty())
                        stk.pop_back();
                }else if(cur != "." and cur != "")
                    stk.push_back(cur);
                cur = "";
                    
            }else
                cur += c;
        }
        string res;
        for(string &d:stk)
            res += "/" + d;
        if(res.empty())
            res = "/";
        return res;
    }
};