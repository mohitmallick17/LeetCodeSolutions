// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    long double a_score = (long double)a.first/a.second;
    long double b_score = (long double)b.first/b.second;
    
    return a_score > b_score;
}

class Solution{
    bool isPowerOfTwo(long long n){
       long long k = sqrt(n);
       return k*k == n;
    }
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    vector<pair<long long, long long>> v(N);
	    for(int i=0;i<N;i++)
	        v[i] = {p[i], w[i]};
	    sort(v.begin(), v.end(), cmp);
	    
	    long double res = 0.0;
	    
	    for(int i=0;i<N;i++){
	        long long wt=v[i].second, cost=v[i].first;
	        if(isPowerOfTwo(wt))continue;
	        if(C >= wt){
	            res += (long double)cost;
	            C -= wt;
	        }else{
	            res += ((double long)cost*C)/(double long)wt;
	            break;
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends