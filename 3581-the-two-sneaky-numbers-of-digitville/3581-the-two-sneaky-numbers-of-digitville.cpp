class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>mpp;
        int count=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto &i:mpp){
            if(i.second>=3){
                ans.push_back(i.first);
                ans.push_back(i.first);
                return ans;
            }
            else if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};