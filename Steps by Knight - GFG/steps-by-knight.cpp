//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    
	    int delrow[] = {-1,1,-1,1,2,-2,2,-2};
	    int delcol[] = {-2,-2,2,2,-1,-1,1,1};
	    
	    int a[N+1][N+1];
	    
	    if(x1==x2 and y1==y2) return 0;
	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<N;j++){
	            a[i][j]=0;
	        }
	    }
	    
	    queue<pair<int,int>> q;
	    q.push({x1-1,y1-1});
	    while(!q.empty()){
	        auto cur = q.front();
	        int row = cur.first;
	        int col = cur.second;
	        q.pop();
	        
	        for(int t=0;t<8;t++){
	            int nrow = row + delrow[t];
	            int ncol = col + delcol[t];
	            if(nrow>=0 and nrow<N and ncol>=0 and ncol<N and a[nrow][ncol]==0){
	                a[nrow][ncol]=a[row][col]+1;
	                q.push({nrow,ncol});
	            }
	        }
	       
	        
	        
	    }
	    
	    return a[x2-1][y2-1];
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends