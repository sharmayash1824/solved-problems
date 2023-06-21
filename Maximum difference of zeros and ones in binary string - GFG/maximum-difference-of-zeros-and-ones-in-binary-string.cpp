//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    vector<int> v;
	    for(int i=0;i<S.length();i++){
	        if(S[i]=='1'){
	            v.push_back(-1);
	        }
	        else{
	            v.push_back(1);
	        }
	    }
	    int maxi = v[0];
	    int sum = 0;
	    for(int i=0;i<v.size();i++){
	        sum += v[i];
	        maxi=max(sum,maxi);
	        if(sum<0){
	            sum=0;
	        }
	    }
	    
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends