class Solution {
    static bool cmp(string &a, string &b){
        return a.size() < b.size();
    }
    bool canFormWord(string &word, unordered_set<string> &st){
        int n=word.size();
        vector<bool> found(n+1, false);
        found[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(found[j] and st.count(word.substr(j, i-j))){
                    found[i]=true;
                    break;
                }
            }
        }
        return found[n];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<string> res;
        unordered_set<string> st;
        
        for(string &word:words){
            if(canFormWord(word, st))
                res.push_back(word);
            st.insert(word);
        }
        
        return res;
    }
};