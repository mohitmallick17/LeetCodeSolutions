class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";
        string res = (numerator<0 ^ denominator<0) ? "-" : "";
        long long num=abs(1LL*numerator);
        long long den=abs(1LL*denominator);
        
        res += to_string(num/den);
        long long rem=num%den;
        if(rem != 0){
            res += '.';
            unordered_map<long, int> mp;
            mp[rem]=res.size();
            while(rem != 0){
                rem *= 10;
                res += to_string(rem/den);
                rem %= den;
                if(mp.find(rem) != mp.end()){
                    int idx = mp[rem];
                    res.insert(idx, "(");
                    res += ')';
                    break;
                }
                mp[rem]=res.size();
            }
        }
        return res;
    }
};