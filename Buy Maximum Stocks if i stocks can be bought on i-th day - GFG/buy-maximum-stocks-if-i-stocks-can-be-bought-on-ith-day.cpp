//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        vector<pair<int,int>> stock;
        
        for(int i=0;i<n;i++){
            stock.push_back({price[i],i+1});
        }
        sort(stock.begin(),stock.end());
        
        int ans=0;
        for(int i=0;i<n;i++){
            int cost = stock[i].first;
            int count = stock[i].second;
            if(cost*count<k){
                ans += count;
                k -= cost*count;
            }
            else{
                ans += k/cost;
                k -= cost*(k/cost);
            }
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends