class Solution {
public:
    bool wordPattern(string pattern, string str){
        unordered_map<string, bool> usedWord;
        unordered_map<char, string> mp;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n)
                return false; // patten length mismatch
            if(mp.count(pattern[i])){
                // exists
                if(mp[pattern[i]] != word)
                    return false; // char mapped to other word
            }else{
                // doesnt exist
                if(usedWord.count(word))
                    return false; // word already used
                mp[pattern[i]] = word;
                usedWord[word]=true;
            }
        }
        return i == n; // if len(pattern) == len(words)
    }
};