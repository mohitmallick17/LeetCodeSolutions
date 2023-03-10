//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)

    {

     

     long long minia=INT_MAX;

     long long minib=INT_MAX;

     long long maxia=INT_MIN;

     long long maxib=INT_MIN;

     long long maxic=INT_MIN;

     

     for(int i=0;i<n;i++)

     {

         long long a=arr[i];

         if(a<minia && a<minib)

         {

             minib=minia;

             minia=a;

         }

         else if(a<minib)

         {

             minib=a;

         }

         

         if(a>maxia && a>maxib && a>maxic)

         {

             maxia=maxib;

             maxib=maxic;

             maxic=a;

         }

         else if(a>maxia && a>maxib)

         {

             maxia=maxib;

             maxib=a;

         }

         else if(a>maxia)

         {

             maxia=a;

         }

     }

     long long a=maxia*maxib*maxic;

     long long b=minia*minib*maxic;

     if(a>b)

         return a;

     return b;

    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends