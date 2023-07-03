//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int dp[1001][1001];
    bool solve(int i,int j,string& wild,string& pattern){
        if(i==-1 && j==-1) return true;
        if(j==-1){
            for(int k=0;k<i;k++){
                if(wild[k]!='*'){
                    return false;  
                } 
                else{
                    return true;
                }
            }
        }
        if(i==-1) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(wild[i]==pattern[j] || wild[i]=='?') return dp[i][j] = solve(i-1,j-1,wild,pattern);
        if(wild[i]=='*'){
            int op1 = solve(i-1,j,wild,pattern);
            int op2 = solve(i,j-1,wild,pattern);
            return dp[i][j]= op1 or op2;
        }
        else return dp[i][j]=0;
        
    }
    bool match(string wild, string pattern)
    {
        memset(dp,-1,sizeof(dp));
        int n=wild.size();
        int n2=pattern.size();
        return solve(n,n2,wild,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends