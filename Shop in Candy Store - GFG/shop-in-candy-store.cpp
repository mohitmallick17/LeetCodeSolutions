// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies+N);
        vector<int> res{0,0};
        int c=0, start=0, end=N-1;
        while(start <= end){
            c += candies[start++];
            end -= K;
        }
        res[0]=c;
        c=0, start=0, end=N-1;
        while(start <= end){
            c += candies[end--];
            start+=K;
        }
        res[1]=c;
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends