//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, string s) {
        // code here
        unordered_map<char,int>temp;
        unordered_map<char,int>outsider;
        int count=0;
        int ans=0;
        int i=0;
        while(i<s.size())
        {
            if(temp[s[i]]==0)
            {
                if(count<n)
                {
                    count++ ;
                    temp[s[i]]=1;
                }
                else
                {
                    ans++ ;
                    temp[s[i]]=1;
                    outsider[s[i]]=1;
                    
                }
            }
            else
            {
                if(outsider[s[i]]==0)
                count-- ;
            }
            
            i++ ;
        }
        
        return ans ;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends