// Last updated: 8/13/2025, 3:33:29 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = n;
    int l = 0;
    
    for (int r = 0; r < n; r++) {
        while (nums[r] > (long long)k * nums[l]) {
            l++;
        }
        int len = r - l + 1;
        ans = min(ans, n - len);
    }
    return ans;  
    }
};