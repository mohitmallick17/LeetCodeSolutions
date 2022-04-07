// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}
class Solution{
public:
    int max_non_overlapping( vector<vector<int>>& ranges ){
        sort(ranges.begin(), ranges.end(), cmp);
        int high=ranges[0][1];
        int len = 1;
        // cout << "(" << ranges[0][0]<<", "<<ranges[0][1] << "), ";
        for(int i=1;i<ranges.size();i++){
            // cout << "(" << ranges[i][0]<<", "<<ranges[i][1] << "), ";
            if(ranges[i][0] >= high){
                high = ranges[i][1];
                len++;
            }
        }
        return len;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends