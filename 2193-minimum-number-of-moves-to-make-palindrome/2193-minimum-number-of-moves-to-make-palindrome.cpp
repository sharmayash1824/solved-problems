class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            int i = l;
            int j = r;
            while(s[i]!=s[j]) j--;
            
            if(i==j){
                swap(s[j],s[j+1]);
                ans++;
                continue;
            }
            else{
                while(j<r){
                    swap(s[j],s[j+1]);
                    ans++,j++;
                }
            }
            l++;
            r--;
        }
        
        return ans;
    }
};