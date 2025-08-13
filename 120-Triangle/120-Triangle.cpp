// Last updated: 8/13/2025, 3:36:46 PM
class Solution {
public:
    // int dp[202][202];
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>prev(n,0);
        for (int j = 0; j < n; j++) {
            prev[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            vector<int>curr(n,0);
            for (int j = i; j>=0; j--) {
                int down = prev[j];
                int diag = prev[j + 1];
               curr[j] = triangle[i][j] + min(down, diag);
            }
            prev=curr;
        }

        return prev[0];
    }
};