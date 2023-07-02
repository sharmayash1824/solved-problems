//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505][2005];
    
    int solve(int i, vector<int> &nums, int rem, int k){
        if(i == nums.size()){
            return 0;
        }
        
        if(dp[i][rem] != -1){
            return dp[i][rem];
        }
        
        int ans = INT_MAX;
        
        if(nums[i] > rem){
            ans = (rem+1)*(rem+1) + solve(i+1, nums, k - nums[i] - 1, k);
        }
        else{
            int choice1 = solve(i+1, nums, rem - nums[i] - 1,k);
            int choice2 = (rem+1)*(rem+1) + solve(i+1, nums, k - nums[i] - 1, k);
            
            ans = min(choice1, choice2);
        }
        
        return dp[i][rem] = ans;
        
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0,nums, k, k);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends