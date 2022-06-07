class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        auto it = products.begin();
        sort(it, products.end());
        
        string key;
        vector<vector<string>> res;
        
        for(const char &c:searchWord){
            vector<string> cur;
            key += c;
            it = lower_bound(it, products.end(), key);
            
            for(int i=0;i<3 and (it+i)!=products.end();i++){
                string &word = *(it+i);
                if(word.find(key) != 0)break;
                cur.push_back(word);
            }
            
            res.push_back(cur);
        }
        return res;
    }
};