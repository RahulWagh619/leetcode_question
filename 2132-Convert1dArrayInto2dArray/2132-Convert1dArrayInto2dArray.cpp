// Last updated: 8/13/2025, 3:33:59 PM
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) {
            return {};  
        }
        vector<vector<int>> a(m,vector<int>(n)); 
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                a[j][i] = original[i + j * n]; 
            }
        }
     return a;
    }
};
