class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans="";
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
        pair<int,char> block={-1,'$'};
        while(!pq.empty()){
            auto itr = pq.top();
            pq.pop();
            ans+=itr.second;
            itr.first--;
            if(block.first>0){
                pq.push(block);
            }
            block=itr;
        }
        
        if(s.length()==ans.length()){
            return ans;
        }
        
        return "";
    }
};