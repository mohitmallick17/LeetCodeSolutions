//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B){
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        priority_queue<pair<int, int>> pq; // {sum, index}
        for(int i=0;i<N;i++){
            pq.push({A[i]+B[0], 0});
        }
        vector<int> res;
        while(K--){
            auto top = pq.top();
            pq.pop();
            int index = top.second;
            int sum = top.first;
            res.push_back(sum);
            
            if(index < N-1){
                pq.push({sum-B[index]+B[index+1], index+1});
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends