class Solution {
    long long mod=1e9 + 7;
    
    bool isPrime(char &c){
        return (c=='2' or c=='3' or c=='5' or c=='7');
    }
    
    int dp[1001][2][1001];
    
    long long solve(int index, bool at_start, int k, string &s, int &minL){
        if(index == s.size())return k==0;
        if(index > s.size() or k==0 or (at_start && !isPrime(s[index])))return 0;
        
        if(dp[index][at_start][k] != -1)return dp[index][at_start][k];
        
        long long ans = 0;
        if(isPrime(s[index])){
            if(at_start)ans = solve(index+minL-1, false, k, s, minL);
            else ans = solve(index+1, false, k, s, minL);
        }else{
            long long next_partition = solve(index+1, true, k-1, s, minL);
            long long extend_cur_partition = solve(index+1, false, k, s, minL);
            
            ans = (next_partition + extend_cur_partition)%mod;
        }
        return dp[index][at_start][k] = ans;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp, -1, sizeof(dp));
        return solve(0, true, k, s, minLength);
    }
};