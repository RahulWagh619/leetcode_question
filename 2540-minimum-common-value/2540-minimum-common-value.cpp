class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        set<int>st;
        for(int i=0;i<n;i++){
           st.insert(nums1[i]);
        }
        for(int i=0;i<m;i++){
            if(st.find(nums2[i])!=st.end())return nums2[i];
        }
        return -1;
    }
};