//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans="";
            unordered_map<char,int> mp;//for counting of the char
            queue<char>q;// it will store the non-repeating character
            for(auto i:A){
                q.push(i);
                mp[i]++;
                while((!q.empty())&&(mp[q.front()]>1)) q.pop();
                if(!q.empty()) ans.push_back(q.front());
                else ans.push_back('#');
            }
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends