class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
        int mxlen = 0;
        string ans;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<=n-1;i++,j++){
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==1){
                    if(j-i+1 > mxlen){
                        mxlen = j-i+1;
                        ans = s.substr(i,mxlen);
                    }
                }
            }
        }
        return ans;
    }
};