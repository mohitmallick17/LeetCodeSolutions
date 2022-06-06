// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k){
        vector<long long> remCnt(k, 0);
        for(int i=0;i<n;i++){
            int rem = A[i] % k;
            remCnt[rem]++;
        }
        long long res = (remCnt[0]*(remCnt[0]-1))/2;
        for(int i=1;i<=k/2;i++){
            if(i==k-i)
                res += (remCnt[i]*(remCnt[i]-1))/2;
            else
                res += remCnt[i]*remCnt[k-i];
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends