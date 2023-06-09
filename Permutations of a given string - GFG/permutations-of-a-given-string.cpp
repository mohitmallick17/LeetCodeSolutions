//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void permu(int i,string S,set<string> &ans)
    {
        if(i>=S.size())
        {
            ans.insert(S);
            return;
        }
        for(int index=i;index<S.size();index++)
        {
            swap(S[index],S[i]);
            permu(i+1,S,ans);
            swap(S[index],S[i]);
        }
    
    }
    
 vector<string>find_permutation(string S)
 {
     set<string> ans;

     vector<string> result;
     permu(0,S,ans);
     
     
     result.assign(ans.begin(),ans.end());
     sort(result.begin(),result.end());
     return result;
 }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends