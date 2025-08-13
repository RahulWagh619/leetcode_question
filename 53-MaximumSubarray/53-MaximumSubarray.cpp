// Last updated: 8/13/2025, 3:37:31 PM
class Solution {
public:
    int printmaxarray(vector<int>& a, int start, int end) {
        if (start == end) return a[start];
        
        int mid = (start + end) / 2;
        int maxleftsum = printmaxarray(a, start, mid);
        int maxrightsum = printmaxarray(a, mid + 1, end);

       
        int maxleftbordersum = INT_MIN;
        int leftsum = 0;
        for (int i = mid; i >= start; i--) {
            leftsum += a[i];
            maxleftbordersum = max(leftsum, maxleftbordersum);
        }

        int maxrightbordersum = INT_MIN;
        int rightsum = 0;
        for (int i = mid + 1; i <= end; i++) {
            rightsum += a[i];
            maxrightbordersum = max(rightsum, maxrightbordersum);
        }

        int crosssum = maxleftbordersum + maxrightbordersum;

        return max(crosssum, max(maxrightsum, maxleftsum));
    }

    int maxSubArray(vector<int>& nums) {
        return printmaxarray(nums, 0, nums.size() - 1);
    }
};
