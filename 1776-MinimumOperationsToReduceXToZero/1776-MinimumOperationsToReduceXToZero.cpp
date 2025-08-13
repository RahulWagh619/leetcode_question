// Last updated: 8/13/2025, 3:34:03 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;
        
        if (target < 0) return -1; // Not possible
        
        int maxLen = -1, sum = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            while (sum > target && left <= right) {
                sum -= nums[left++];
            }
            
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};
