class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> dna, res;
        
        for(int i=0;i+10<=s.size();i++){
            string key = s.substr(i, 10);
            if(dna.count(key))res.insert(key);
            else dna.insert(key);
        }
        return vector<string>(res.begin(), res.end());
    }
};