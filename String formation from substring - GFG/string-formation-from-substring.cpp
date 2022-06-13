// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    // Your code goes here
	    int n=s.size();
	    queue<char>q;
	    q.push(s[0]);
	    
	    for(int i=1;i<n;i++)
	    {
	        if(q.front()==s[i])
	        {
	            q.pop();
	        }
	        q.push(s[i]);
	    }
	    if(q.size()==n)
	    {
	        return false;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(q.front()!=s[i])
	        {
	            return false;
	        }
	        q.pop();
	        q.push(s[i]);
	        
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends