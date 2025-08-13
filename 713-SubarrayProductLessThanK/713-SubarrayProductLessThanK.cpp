// Last updated: 8/13/2025, 3:35:01 PM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count=0;
        int i=0;
        long long product=1;
        int n=nums.size();
        for (int j = 0; j < nums.size(); j++) {
            product *= nums[j];
            while (product >= k) {
                product /= nums[i];
                i++;
            }
            count += (j - i + 1);
        }
        return count;
    }
};