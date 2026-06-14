class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map<int,int>mpp;
            map<int,int>freq;
            for(int j=i;j<n;j++){
                if(mpp[nums[j]]>0){
                    freq[mpp[nums[j]]]--;
                    if(freq[mpp[nums[j]]]==0){
                        freq.erase(mpp[nums[j]]);
                    }
                }
                mpp[nums[j]]++;
                freq[mpp[nums[j]]]++;
                if(freq.size()>2){
                    continue;
                }
                if(freq.size()==1 && mpp.size()==1){
                    ans=max(ans,j-i+1);
                }
                else if(freq.size()==2){
                   vector<int>v;
                    for(auto &m:freq){
                       v.push_back(m.first);
                    }
                    sort(v.begin(),v.end());
                    if(v[0]*2==v[1]){
                        ans=max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};