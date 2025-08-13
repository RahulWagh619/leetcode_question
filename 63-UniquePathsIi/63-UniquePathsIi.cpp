// Last updated: 8/13/2025, 3:37:23 PM
class Solution
{
public:

    bool possible(vector<vector<int>> &obstacleGrid, int i, int j, int n, int m)
    {
        if (i <0 || j<0)
            return false;
        if (obstacleGrid[i][j] == 1)
            return false;
        return true;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1||obstacleGrid[n-1][m-1] == 1)return 0;
        vector<int>prev(m,0);
        for (int i = 0; i < n; i++)
        {
            vector<int>temp(m,0);
            for (int j = 0; j < m; j++)
            {
                if(i==0 && j==0){
                    temp[j]=1;
                }
                if (possible(obstacleGrid, i, j - 1, n, m))
                {
                    temp[j]+=temp[j - 1];
                }
                if (possible(obstacleGrid, i - 1, j, n, m))
                {
                    temp[j]+= prev[j];
                }
            }
            prev=temp;
        }
        return prev[m - 1];
    }
};