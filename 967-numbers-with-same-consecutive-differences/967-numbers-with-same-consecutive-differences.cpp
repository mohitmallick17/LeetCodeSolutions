class Solution {
    vector<int> res;
    void solve(long long num, int n, int k){
        if(n==0){
            res.push_back(num);
            return;
        }
        int prev_d = num%10;
        if(k==0){
            solve(num*10 + prev_d, n-1, k);
        }else{
            int new_d=prev_d-k;
            if(new_d>=0)
                solve(num*10 + new_d, n-1, k);
            new_d=prev_d+k;
            if(new_d<10)
                solve(num*10 + new_d, n-1, k);            
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for(long long i=1;i<=9;i++){
            // i = first digit
            solve(i, n-1, k);
        }
        return res;
    }
};

/*
10 digit

for each digit = 0 to 9

1
2
3
4
5
6
7
8
9

*/