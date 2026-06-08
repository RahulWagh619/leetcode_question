class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count=0;
        int n=nums.size();
        vector<int>less;
        vector<int>more;
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                count++;
            }
            else if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else{
                more.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<less.size();i++){
            ans.push_back(less[i]);
        }
        while(count--){
            ans.push_back(pivot);
        }
         for(int i=0;i<more.size();i++){
            ans.push_back(more[i]);
        }
        return ans;
    }
};