//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string> v;
    void dfs(int i,int j,string s,vector<vector<int>> m,int n,vector<vector<int>> &visited){
        if(i<0 or j<0 or i>=n or j>=n) return;
        if(m[i][j]==0 or visited[i][j]==1) return;
        if(i==n-1 and j==n-1){
            v.push_back(s);
            return;
        }
        visited[i][j]=1;
        
        dfs(i-1,j,s+'U',m,n,visited);
        dfs(i+1,j,s+'D',m,n,visited);
        dfs(i,j-1,s+'L',m,n,visited);
        dfs(i,j+1,s+'R',m,n,visited);
        
        
        visited[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        v.clear();
        vector<vector<int>> visited(n,vector<int>(n));
        if(m[0][0]==0) return v;
        if(m[n-1][n-1]==0) return v;
        string s="";
        dfs(0,0,s,m,n,visited);
        
        sort(v.begin(),v.end());
        return v;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends