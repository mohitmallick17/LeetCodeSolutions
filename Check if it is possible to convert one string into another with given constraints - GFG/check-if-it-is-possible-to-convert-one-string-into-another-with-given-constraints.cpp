//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isItPossible(string S, string T, int M, int N)
    {
        if(M != N)return 0;
        // code here
        if (count(S.begin(), S.end(), '#') != count(T.begin(), T.end(), '#'))
            return false;
        int i = 0, j = 0;
        while (i < M and j < N)
        {
            while (i < M and S[i] == '#')
                i++;

            while (j < N and T[j] == '#')
                j++;

            if ((i < M and j < N) and ((S[i] != T[j]) or (S[i] == 'A' and i < j) or (S[i] == 'B' and i > j)))
                return false;
            i++;
            j++;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends