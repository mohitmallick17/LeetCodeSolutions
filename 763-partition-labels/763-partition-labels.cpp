class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26, 0);
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a']=i;
        }
        int len = 0;
        int maxD = -1;
        vector<int> res;
        for(int i=0;i<s.size();i++){
            maxD = max(maxD, pos[s[i]-'a']);
            len++;
            if(i == maxD){
                res.push_back(len);
                len = 0;
            }
        }
        return res;
    }
};