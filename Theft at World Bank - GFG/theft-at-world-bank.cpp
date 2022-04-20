// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    long long a_score = (a.second == 0 ? 0 : (a.first/a.second));
    long long b_score = (b.second == 0 ? 0 : (b.first/b.second));
    
    return a_score > b_score;
}

class Solution{
//     bool isPowerOfTwo(long long n)
//     {
//         /* First x in the below expression is for the case when x is 0 */
//         // return x && (!(x&(x-1)));
        
//       long long  k = sqrt(n);
//       return k * k == n;
//     }
// 	public:
// 	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
// 	    vector<pair<long long, long long>> v(N);
// 	    for(int i=0;i<N;i++)
// 	        v[i] = {p[i], w[i]};
// 	    sort(v.begin(), v.end(), cmp);
	    
// 	    long double res = 0;
	    
// 	    for(auto &x:v){
// 	        if(isPowerOfTwo(x.second))continue;
// 	        long long amt = min(C, x.second);
// 	        res += ((x.first/(long double)x.second)*amt);
// 	        C -= amt;
// 	    }
// 	    return res;
// 	}
bool perfectSquare(long long  n){
       long long  k = sqrt(n);
       return k * k == n;
   }
   static bool comp(pair<long long , long long>& a , pair<long long ,long long >& b){
       return a.second * b.first > a.first * b.second;
   }
public:
long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> P){
    // Code here.
    pair<long long ,long long>p[N];
    for(int i = 0 ; i < N; i++)
    p[i] = {w[i] , P[i]};
    sort(p , p + N , comp);
    long double res = 0.0;
    for(int i = 0 ; i < N ; i++){
        long long cost = p[i].second , weight = p[i].first;
        if(perfectSquare(weight))
        continue;
        if(weight <= C)
        {
            res += (double)cost;
            C -= weight;
        }
        else{
            res += (double)(cost * C) / (double)weight;
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