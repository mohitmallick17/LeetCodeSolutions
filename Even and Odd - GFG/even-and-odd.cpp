// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    bool isFit(int num, bool isOdd){
        if(isOdd)
            return (num&1)==1;
        else
            return (num&1)==0;
    }
  public:
    void reArrange(int arr[], int N){
        int ei=N-2, oi=N-1;
        
        for(int i=0;i<N;i++){
            while(!isFit(arr[i], i&1)){
                if(arr[i]&1){ // odd num
                    swap(arr[i], arr[oi]);
                    oi-=2;
                }
                else{ // even
                    swap(arr[i], arr[ei]);
                    ei-=2;
                }
            }
        }
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends