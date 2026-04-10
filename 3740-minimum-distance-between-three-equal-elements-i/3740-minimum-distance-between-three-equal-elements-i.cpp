class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=INT_MAX;
        for(auto &i:mpp){
            if(i.second<3){
                continue;
            }
            int val=i.first;
            vector<int>a;
            for(int j=0;j<n;j++){
                if(nums[j]==val){
                a.push_back(j);
                }
            }
            for(int j=2;j<a.size();j++){
                 int z=a[j]-a[j-1];
                 z+=a[j-1]-a[j-2];
                 z+=a[j]-a[j-2];
                 ans=min(ans,z);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};