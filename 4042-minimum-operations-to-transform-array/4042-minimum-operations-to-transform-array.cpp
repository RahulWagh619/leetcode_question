class Solution {
public:
typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
         ll count=1;
         int val=nums2[nums2.size()-1];
         bool found=false;
         int mini=INT_MAX;
         for(int i=0;i<nums1.size();i++){
            count+=abs(nums1[i]-nums2[i]);
            if(min(nums1[i],nums2[i])<=val && max(nums1[i],nums2[i])>=val){
                mini=0;
            }
            else{
                int diff1=abs(val-nums1[i]);
                int diff2=abs(val-nums2[i]);
                int min2=min(diff2,diff1);
                mini=min(mini,min2);
            }
         }
         cout<<mini<<endl;
         return count+mini;
    }
};