// Last updated: 8/13/2025, 3:34:02 PM
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        const long long mod = 1e9 + 7;
        int n = a.size();
        long long sum = 0;
        int maxDiffReduction = 0; // Stores the max improvement we can get

        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end()); // Sort for binary search

        for (int i = 0; i < n; i++) {
            int diff = abs(a[i] - b[i]);
            sum = (sum + diff) % mod;

            // Binary search to find the closest value in sortedA
            int start = 0, end = n - 1, mini = diff;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                mini = min(mini, abs(sortedA[mid] - b[i]));

                if (sortedA[mid] < b[i]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            // Update the max possible improvement
            maxDiffReduction = max(maxDiffReduction, diff - mini);
        }

        return (sum - maxDiffReduction + mod) % mod;
    }
};
