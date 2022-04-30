// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    vector<vector<int>> v(1, vector<int>(26, 0));
	    
	    for(int i=0;i<str.size();i++){
	        vector<int> cur = v.back();
	        char c=str[i];
	        cur[c-'a']++;
	        v.push_back(cur);
	    }
	    vector<int> res;
	    for(auto &q:Query){
	        int l=q[0], h=q[1];
	        int cnt=0;
	        for(int i=0;i<26;i++){
	            if(v[h][i] > v[l-1][i])cnt++;
	        }
	        res.push_back(cnt);
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends