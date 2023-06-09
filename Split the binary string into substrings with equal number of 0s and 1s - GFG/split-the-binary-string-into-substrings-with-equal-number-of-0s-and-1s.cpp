//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count0=0;
        int count1=0;
        int ans = 0;
        int len=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                count0++;
            }
            else if(str[i]=='1'){
                count1++;
            }
            if(count0==count1){
                ans++;
                len+=count1+count0;
                
                count0=0;
                count1=0;
            }
        }
        
        if(len==str.length()){
            return ans;
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends