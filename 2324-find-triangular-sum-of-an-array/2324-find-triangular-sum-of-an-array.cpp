class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<vector<int>>val;
        val.push_back(nums);
        if(nums.size()==1){
            return nums[0];
        }
        while(val[val.size()-1].size()!=2){
            vector<int>z;
            for(int i=1;i<val[val.size()-1].size();i++){
                z.push_back((val[val.size()-1][i]+val[val.size()-1][i-1])%10);
            }
            val.push_back(z);
        }
        int val1=(val[val.size()-1][1]+val[val.size()-1][0])%10;
        return val1;
    }
};