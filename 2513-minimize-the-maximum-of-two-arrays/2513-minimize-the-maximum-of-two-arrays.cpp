class Solution {
    long long gcd(long long a, long long b){
        if(b==0)return a;
        return gcd(b, a%b);
    }
public:
    int minimizeSet(int d1, int d2, int c1, int c2) {
        long long l=0, h=1e10;
        long long lcm = (1LL*d1*d2)/gcd(d1, d2);
        long long ans = 0;
        
        while(l <= h){
            long long mid = l + (h-l)/2;
            
            bool cond1 = (mid - mid/d1) >= c1;
            bool cond2 = (mid - mid/d2) >= c2;
            bool cond3 = (mid - mid/lcm) >= c1+c2;
            
            if(cond1 & cond2 & cond3){
                ans=mid;
                h=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};

/*
1 to 1e9
mid = 1e8

can I have 1e8 as max
for(i=1 to 1e8)
    if(!divisible(d1) && cuc1<uc1)cuc1++
    else if(!divisible(d2) && cuc2<uc2)cuc2++



2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
    .       .        .        .        .
1 2 3 4 5 6 7 8 9 .......... 1e8
set d1 <= d2
let d1 = 2
d2 = 3
then, some or all occurences of d1 are overlapped in d2. count of that = all factors of LCM(d1, d2)
LCM * GCD = A*B
LCM = A*B/GCD = L

d1 count -> mid/d1 let it be X1 = min(uc1, X1) = Z1;
if(X1 < uc1)false;
LCM_COMMON = min((mid/L), X1); // either all nos are common, or upper bound to Z1

d2 count -> mid/d2 let it be X2 = min(uc2, X2-LCM_COMMON);
if(X < uc2)false;

return cuc1==uc1 & cuc2==uc2;
*/