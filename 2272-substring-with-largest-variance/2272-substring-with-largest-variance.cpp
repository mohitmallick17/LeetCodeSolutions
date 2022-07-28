class Solution {
    int kadanesAlgo(string &s, char c1, char c2){
        // Always, count(c1) > count(c2)
        // if count(c1) < count(c2): reset count
        int res=0;
        int cnt1=0, cnt2=0;
        for(char &c:s){
            if(c==c1)cnt1++;
            if(c==c2)cnt2++;
            if(cnt2>cnt1)cnt1=0, cnt2=0;
            if(cnt1>0 and cnt2>0)res=max(res, cnt1-cnt2);
        }
        return res;
    }
public:
    int largestVariance(string s) {
        int res=0;
        unordered_set<char> uset(s.begin(), s.end());
        
        for(char ch1:uset){
            for(char ch2:uset){
                if(ch1==ch2)continue;
                res = max(res, kadanesAlgo(s, ch1, ch2));
                string rev = s;
                reverse(rev.begin(), rev.end());
                res = max(res, kadanesAlgo(rev, ch1, ch2));
            }
        }
        return res;
    }
};