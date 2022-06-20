class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        
        for(auto &w:words){
            for(int i=1;i<w.size();i++)
                st.erase(w.substr(i));
        }
        int cnt=0;
        for(auto &x:st)cnt += x.size()+1;
        return cnt;
    }
};