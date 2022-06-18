class TrieNode{
public:
    vector<TrieNode*> children;
    int index;
    TrieNode(){
        children.resize(27, NULL);
        index=-1;
    }
};
class WordFilter {
    TrieNode* root;
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        
        for(int idx=0;idx<words.size();idx++){
            string s = words[idx] + "{";
            
            for(int i=0;i<s.size();i++){
                TrieNode* cur = root;
                for(int j=i;j<(2*s.size()) - 1; j++){
                    int cur_ch = s[j%s.size()];
                    int ch_idx = cur_ch - 'a';
                    if(cur->children[ch_idx]==NULL)
                        cur->children[ch_idx]=new TrieNode();
                    cur = cur->children[ch_idx];
                    cur->index=idx;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string key = suffix + "{" + prefix;
        TrieNode* cur = root;
        for(char &c:key){
            int idx = c-'a';
            if(cur->children[idx]==NULL)
                return -1;
            cur = cur->children[idx];
        }
        return cur->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */