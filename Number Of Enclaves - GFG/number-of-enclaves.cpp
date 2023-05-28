//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        int drow[] = {-1,0,1,0}; 
	    int dcol[] = {0,1,0,-1};
	    
	    
	    for(int j=0;j<m;j++){
            // firstrow
            if(!vis[0][j] and  grid[0][j]==1){
                q.push({0,j});
                vis[0][j]=1;
            }
            // last row
            if(!vis[n-1][j] and grid[n-1][j]==1){
                q.push({n-1,j});
                vis[n-1][j]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            // firstrow
            if(!vis[i][0] and  grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            // last row
            if(!vis[i][m-1] and grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col +dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends