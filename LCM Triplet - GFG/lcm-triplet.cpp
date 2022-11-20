//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   long long lcmTriplets(long long N) {

        // code here

        long long pro1=0,pro2=0;

        if(N==1)

          return 1;

         else if(N==2)

           return 2;

        if(N%2==0){

         pro1=(N-1)*(N-2)*(N-3);

         pro2=(N)*(N-1)*(N-3);

         if(N%3==0&&(N-3)%3==0)

         pro2=pro2/3;

         if(pro1>pro2)

         return pro1;

         else

           return pro2;

        }

        else{

          pro1=(N)*(N-1)*(N-2);

        return pro1;

        }

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends