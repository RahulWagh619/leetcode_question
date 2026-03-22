class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        bool even=true;
        if(nums1[0] & 1){
            even=false;
        }
        if(!even)return true;
        for(int i=0;i<n;i++){
            if(nums1[i] & 1){
                return false;
            }
        }
        return true;
    }
};