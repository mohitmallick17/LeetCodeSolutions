class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> ans;
        
        for(int i=0;i<names.size();i++){
            if(mp.find(names[i]) != mp.end()){
                int suff = mp[names[i]]+1;
                while(true){
                    string cur = names[i] + "(" + to_string(suff) + ")";
                    if(mp.find(cur) == mp.end()){
                        ans.push_back(cur);
                        mp[names[i]]=suff;
                        mp[cur]=0;
                        break;
                    }
                    suff++;
                }
            }else{
                ans.push_back(names[i]);
                mp[names[i]]=0;
            }
        }
        return ans;        
    }
};