//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        int a = 1 ,b=2, ans=0;
        if(n<=2){
            return n;
        }
        int mod = 1000000007;
        for(long long int i=3;i<=n;i++){
            ans = (b%mod + ((i-1)*a)%mod)%mod;
            a = b;
            b = ans;
        }
        
        return ans;
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends