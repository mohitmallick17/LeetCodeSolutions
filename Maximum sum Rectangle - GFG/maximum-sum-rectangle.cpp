// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int aux[C];
        
        
        int maxSum=INT_MIN;
        for(int i=0;i<R;++i){
            memset(aux,0,sizeof(aux));
            for(int j=i;j<R;++j){
                
                
                for(int k=0;k<C;++k)
                    aux[k] += M[j][k];
                
                
                // kadane's algorithm
                int meh=0, msf=INT_MIN;
                for(int k=0;k<C;k++){
                    meh += aux[k];
                    
                    msf=max(meh,msf);
                    
                    if(meh < 0)
                        meh=0;
                }
                maxSum=max(maxSum,msf);
                
            }
                
        }
        return maxSum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends