//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>distance(n,1e9+7);
        int cycle=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<edges.size();j++){
                int x=edges[j][0];
                int y=edges[j][1];
                int weight=edges[j][2];
                if(distance[x]+weight<distance[y]){
                    if(i==n-1){
                        cycle=1;
                    }
                    distance[y]=distance[x]+weight;
                }
            }
        }
        return cycle;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends