// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int solve(int start, int Sum, string &s, vector<vector<int>> &dp){
        if(start == s.size())return 1;
        if(dp[start][Sum] != -1)return dp[start][Sum];
        int curSum = 0;
        int res = 0;
        for(int i=start;i<s.size();i++){
            curSum += s[i] - '0';
            if(curSum >= Sum)
                res += solve(i+1, curSum, s, dp);
        }
        return dp[start][Sum]=res;
    }
	public:
	int TotalCount(string s){
	    vector<vector<int>> dp(s.size(), vector<int>((s.size() * 9) + 1, -1));
	    return solve(0, 0, s, dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends