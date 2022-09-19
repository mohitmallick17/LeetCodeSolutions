class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content;
        
        for(auto p:paths){
            stringstream ss(p);
            string root;
            getline(ss, root, ' ');
            string cur;
            while(getline(ss, cur, ' ')){
                string filePath = root + '/' + cur.substr(0, cur.find('('));
                string data = cur.substr(cur.find('(')+1, (cur.find(')')-cur.find('(')-1));
                content[data].push_back(filePath);
            }
        }
        vector<vector<string>> res;
        
        for(auto &c:content){
            if(c.second.size() > 1)res.push_back(c.second);
        }
        return res;
    }
};