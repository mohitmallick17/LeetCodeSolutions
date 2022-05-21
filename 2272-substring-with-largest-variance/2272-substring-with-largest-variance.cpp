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
        cout << kadanesAlgo(s, 'i', 'a') << '\n';
        int res=0;
        vector<bool> freq(26, 0);
        for(char &c:s)freq[c-'a']=1;
        
        for(int i=0;i<2;i++){
            for(char ch1='a';ch1<='z';ch1++){        
                for(char ch2='a';ch2<='z';ch2++){
                    if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a'])continue;
                    res = max(res, kadanesAlgo(s, ch1, ch2));
                }
            }
            reverse(s.begin(), s.end());
        }
        return res;
    }
};