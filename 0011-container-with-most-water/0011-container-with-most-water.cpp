class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int n=height.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int val=min(height[l],height[r])*(r-l);
            maxi=max(val,maxi);
            if(height[l]>=height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxi;


    }
};