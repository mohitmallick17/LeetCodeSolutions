// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    double BS(double low, double high, double v[], int n){
        
        while(low < high){
            double mid = (low+high)/2;
            double force = 0.0;
            for(int i=0;i<n;++i){
                force += 1/(mid-v[i]);
            }
            if(abs(force) <= 0.000001)return mid;
            else if(force < 0)high=mid;
            else low=mid;
        }
        return low;
    }
public:
    void nullPoints(int n, double magnets[], double getAnswer[]){
        for(int i=0;i<n-1;i++)
            getAnswer[i] = BS(magnets[i], magnets[i+1], magnets, n);
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
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends