class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count = 0;
        map<int, vector<int>> mppx;  // x -> list of y values
        map<int, vector<int>> mppy;  // y -> list of x values
        
        // Populate maps
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            mppx[x].push_back(y);
            mppy[y].push_back(x);
        }
        
        // Sort all vectors
        for (auto& pair : mppx) {
            sort(pair.second.begin(), pair.second.end());
        }
        for (auto& pair : mppy) {
            sort(pair.second.begin(), pair.second.end());
        }
        
        // Check each building
        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];
            vector<int>& ysAtX = mppx[x];
            vector<int>& xsAtY = mppy[y];
            
            // Check if building has neighbors on all 4 sides
            bool hasYBelow = ysAtX[0] < y;
            bool hasYAbove = ysAtX[ysAtX.size() - 1] > y;
            bool hasXLeft = xsAtY[0] < x;
            bool hasXRight = xsAtY[xsAtY.size() - 1] > x;
            
            if (hasYBelow && hasYAbove && hasXLeft && hasXRight) {
                count++;
            }
        }
        
        return count;
    }
};
