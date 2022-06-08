// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<=k;i++)
            pq.push(arr[i]);
        vector<int> res;
        
        for(int i=k+1;i<n;i++){
            int top = pq.top();
            pq.pop();
            pq.push(arr[i]);
            res.push_back(top);
        }
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            res.push_back(top);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends