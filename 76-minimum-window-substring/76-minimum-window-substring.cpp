class Solution {
    bool isSubset(unordered_map<char, int> &a, unordered_map<char, int> &b){
        for(auto &x:b){
            if(a[x.first] < x.second)return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        for(char &c:t)ht[c]++;
        
        int head=0, tail=-1;
        for(int start=0, end=0;end<s.size();end++){
            hs[s[end]]++;
            
            while(start<=end and isSubset(hs,ht)){
                if(tail==-1 or tail-head > end-start)
                    head=start, tail=end;
                if(start==end)break;
                hs[s[start]]--;
                start++;
            }
        }
        return tail==-1 ? "" : s.substr(head, tail-head+1);
    }
};