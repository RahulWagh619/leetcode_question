// Last updated: 8/13/2025, 3:36:08 PM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX;
        int i=0;
        int j=0;
        int sum=0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            // Shrink the window while the sum is >= target
            while (sum >= target) {
                mini = min(mini, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        if(mini==INT_MAX)return 0;
        return mini;
    }
};