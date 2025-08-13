// Last updated: 8/13/2025, 3:33:40 PM
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mini=INT_MAX;
        map<long long,long long>mp;
        for(int  i=0;i<basket1.size();i++){
            mini=min({mini,basket1[i],basket2[i]});
            mp[basket1[i]]++;
            mp[basket2[i]]++;
        }
        bool isans=true;
        for(auto &i:mp){
            if(i.second & 1){
                isans=false;
                break;
            }
        }
        if(!isans){
           return -1;
        }
        // sort(basket1.begin(),basket1.end());
        // sort(basket2.begin(),basket2.end());
        map<long long,long long>k;
        vector<long long>ans;
        for(int i=0;i<basket1.size();i++){
            k[basket1[i]]++;
        }
        for(auto &i:mp){
            long long val=k[i.first];
            long long diff=abs(i.second/2-val);
            for (int j = 0; j < diff; j++) {
                ans.push_back(i.first);
            }
        }
        long long sum=0;
        int size=ans.size()/2;
        sort(ans.begin(),ans.end());
        for(int i=0;i<size;i++){
            sum+=min(2LL*mini,ans[i]);
        }
        return sum;
    }
};