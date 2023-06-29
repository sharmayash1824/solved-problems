//{ Driver Code Starts
// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long int disarrange(int N){
        // code here
        long int dp[N+1]={0};
        long int mod = 1000000007;
        
        dp[1]=0;
        dp[2]=1;
        
        for(long int i=3;i<=N;i++){
            dp[i] = ((i-1)*((dp[i-1])%mod+(dp[i-2])%mod))%mod;
        }
        
        return dp[N];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends