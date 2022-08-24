class Solution {
    long long makePalin(long long start, bool isOdd){
        long long res = start;
        if(isOdd)start/=10;
        
        while(start > 0){
            res = (res*10) + start%10;
            start /= 10;
        }
        return res;
    }
public:
    string nearestPalindromic(string n) {
        int len=n.size();
        long left;
        if(len & 1)
            left = stol(n.substr(0, len/2 + 1));
        else
            left = stol(n.substr(0, len/2));
        
        vector<long long> candidates;
        candidates.push_back(makePalin(left, len & 1));
        candidates.push_back(makePalin(left+1, len & 1));
        candidates.push_back(makePalin(left-1, len & 1));
        candidates.push_back((long long)pow(10, len-1)-1LL);
        candidates.push_back((long long)pow(10, len)+1LL);
        
        long long ans = 0;
        long long diff = LONG_MAX;
        long long num = stol(n);
        
        for(auto &c:candidates){
            if(c == num)continue;
            long long cur_diff = labs(c-num);
            if(cur_diff < diff){
                diff = cur_diff;
                ans=c;
            }else if(cur_diff == diff and c < ans)
                ans = c;
        }
        return to_string(ans);
    }
};