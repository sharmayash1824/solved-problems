//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int right_up = (j - 1)>= 0 ? M[j - 1][i + 1] : 0;
                int right = M[j][i + 1];
                int right_down = (j + 1)< n ? M[j + 1][i + 1] : 0;
                M[j][i] += max({right , right_up , right_down});
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,M[i][0]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends