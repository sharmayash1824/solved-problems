//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here \]
  
  string ans="";
  int count=0;
  for(int i=0;i<src.length();i++){
      int k=i;
      while(src[i]==src[k] and k<src.length()){
          count++;
          k++;
      }
      ans+=(src[i]+to_string(count));
      count=0;
      i=k-1;
  }
  
  return ans;
}     
 
