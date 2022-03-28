// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n){
        vector<int> bits(32);
        for(int i=31;i>=0;i--){
            bits[i] = (x&1);
            x >>= 1;
        }
        int i=31-p1; // bit_index: 0 to 31, subtract the position of p1'th bit from right
        int j=31-p2;
        
        for(int c=0;c<n and i>=0 and j>=0;c++,i--,j--)
            swap(bits[i], bits[j]);
        int ans = 0;
        
        for(int i=0;i<32;i++){
            if(bits[i])
                ans |= (1<<(31-i));
        }
        return ans;
    }
};

// { Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,p1,p2,n;
		cin>>x>>p1>>p2>>n;
		Solution obj;
		int res=obj.swapBits(x,p1,p2,n);
		printf("%d\n", res);
	}
    return 0;
}  // } Driver Code Ends