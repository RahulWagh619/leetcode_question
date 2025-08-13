// Last updated: 8/13/2025, 3:37:29 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>ans;
        int m=a.size();
    int n=a[0].size();
    int top=0;
    int bottom=m-1;
    int right=n-1;
    int left=0;
    while(top<=bottom && left<=right){
        for (int i = left; i <=right; i++)
        {
            ans.push_back(a[top][i]);
        }
        top++;
        for (int i = top; i <=bottom; i++)
        {
           ans.push_back(a[i][right]);
        }
        right--;
       if(top<=bottom){
        for (int i = right; i >=left; i--)
        {
           ans.push_back(a[bottom][i]);
        }
        bottom--;
     }
         if(left<=right){
        for (int i = bottom; i >=top; i--)
        {
           ans.push_back(a[i][left]);
        }
        left++;
         }
    }
 return ans;
        
    }
};