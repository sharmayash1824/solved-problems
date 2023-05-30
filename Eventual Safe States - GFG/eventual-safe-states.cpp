//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        // BY TOPOSORT
        
        vector<int> adjrev[V];
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            
            for(auto it : adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safenodes;
        
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends