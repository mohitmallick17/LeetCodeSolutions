long long fact[100009];
class Solution {
    long long mod = 1e9 + 7;
    
    
long long binaryExp(long long a, long long b, long long mod=1e9+7){
	long long ans=1;

	while(b){
		if(b&1){
			ans = (ans * a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return ans;
}

long long inverseModulo(long long b, long long mod=1e9+7){
	// To-Do: Find (A/B)%M
	// (A/B)%M = (A * B^-1)%M
	// 		   = (A % M * (B^-1) % M)%M
	// By Fermat's theorem, B^-1 = (B^M-2) % M
	// Condition: M is prime & B is not a multiple of M
	// find B-1 using binary exponentiation
	return binaryExp(b, mod-2, mod);
}
    
    void factorial(int n){
        fact[0]=fact[1]=1;
        for (long long i = 2; i <= n; i++)
            fact[i] = (fact[i-1] * i)%mod;
    }
    
    long long solve(string &s){
        vector<int> freq(26, 0);
        for(auto &x:s)freq[x-'a']++;
        long long num = fact[s.size()];
        long long den=1;
        for(int i=0;i<26;i++)
            den = (den * fact[freq[i]])%mod;
        long long ans = ((num%mod) * (inverseModulo(den, mod)%mod))%mod;
        return ans;
    }
public:
    int countAnagrams(string s) {
        factorial(s.size());
        string tmp;
        stringstream ss(s);
        long long ans = 1;
        while(getline(ss, tmp, ' ')){
            ans = (ans * solve(tmp))%mod;
            // cout << tmp << '\n';
        }
        return ans;
    }
};