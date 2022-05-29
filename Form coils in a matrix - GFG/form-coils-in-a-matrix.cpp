// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        // code here
        int m = 8*n*n;
        
        vector<int> coil1(m);
        vector<vector<int>> ans;
        
        int signFlag = 1;
        int steps = 2;
        
        coil1[0] = 8*n*n + 2*n;
        int curr = coil1[0];
        int index = 1;
        
        while(index < m)
        {
            for(int i=0; i<steps; i++)
            {
                curr = (curr - 4*n*signFlag);
                coil1[index] = curr;
                index++;
                if(index>=m)
                {
                    break;
                }
            }
            
            if(index>=m)
            {
                break;
            }
            
            for(int i=0; i<steps; i++)
            {
                curr = (curr + signFlag);
                coil1[index] = curr;
                index++;
                if(index>=m)
                {
                    break;
                }
            }
            
            signFlag = signFlag * -1;
            steps += 2;
        }
        
        // for(auto it : coil1)
        //     cout<<it<<" ";
        // code here
        
        vector<int> coil2(m);
        
        for(int i=0; i<m; i++)
        {
            coil2[i] = (16*n*n) + 1 - coil1[i];
        }
        
        // for(auto it : coil2)
        //      cout<<it<<" ";
        
        ans.push_back(coil1);
        ans.push_back(coil2);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends