//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int lengthOfLIS(int nums[], int n) {
        vector<int> res(n);
        int size=0;
        
        for(int i=0;i<n;i++){
            int num=nums[i];
            int low=0, high=size;
            while(low<high){
                int mid=low+(high-low)/2;
                if(res[mid] < num)
                    low=mid+1;
                else
                    high=mid;
            }
            res[low]=num;
            if(low==size)size++;
        }
        return size;
    }
  public:
    int removeStudents(int H[], int N) {
        // code here
        // map<int, int> mp;
        // mp[0]=0;
        // int ans=0;
        // for(int i=0;i<N;i++){
        //     auto it = mp.lower_bound(H[i]);
        //     it--;
        //     int curLen = it->second+1;
        //     mp[H[i]] = max(mp[H[i]], curLen);
        //     cout << mp[H[i]] << " ";
        //     ans = max(ans, mp[H[i]]);
        // }
        return N-lengthOfLIS(H,N);
    }
    // 1 8 5 6 4 9
    // 1 2 2 3 2 4
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends