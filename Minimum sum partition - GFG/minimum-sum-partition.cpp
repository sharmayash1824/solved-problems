//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int range = 0;
        for(int i=0;i<n;i++){
            range+= arr[i];
        }
        
        bool t[n+1][range+1];
        vector<int> v;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=range;j++){
                if(i==0){
                    t[0][j]=false;
                }
                if(j==0){
                    t[i][0]=true;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=range;j++){
                if(arr[i-1]<=j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else if(arr[i-1]>j){
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        for(int j=0;j<=range;j++){
            if(t[n][j]==true){
                v.push_back(j);
            }
        }
            
            
        int mindiff = INT_MAX;
        for(int i=0;i<=v.size()/2;i++){
            mindiff = min(mindiff,abs(range - 2 * v[i]));
        }
        
        return mindiff;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends