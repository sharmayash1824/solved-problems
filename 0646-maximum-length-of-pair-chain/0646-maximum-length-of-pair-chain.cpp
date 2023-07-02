class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        int dp[n];
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({pairs[i][0],pairs[i][1]});
        }
        
        sort(p.begin(),p.end());
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(p[i].first>p[j].second){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        
        int ma = 0;
        for(int i=0;i<n;i++){
            ma = max(ma,dp[i]);
        }
        
        return ma;
    }
};