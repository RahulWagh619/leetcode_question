// Last updated: 8/19/2025, 8:59:17 PM
class Solution {
public:
double epsilon=1e-6;
bool helper(vector<double>&nums){
    if(nums.size()==1){
        return abs(nums[0]-24)<=epsilon;
    }
       for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(i==j){
                continue;
            }
            vector<double>temp;
            for(int k=0;k<nums.size();k++){
                if(k!=i && k!=j){
                    temp.push_back(nums[k]);
                }
            }
            double a=nums[i];
            double b=nums[j];
            vector<double>ops{a-b,b-a,a+b,a*b};
            if(abs(a)>0.0){
                ops.push_back(b/a);
            }
            if(abs(b)>0.0){
                ops.push_back(a/b);
            }
            for(auto x:ops){
                temp.push_back(x);
                if(helper(temp)){
                    return true;
                }
                temp.pop_back();
            }
        }
       }
       return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(int i=0;i<cards.size();i++){
            nums.push_back((double)cards[i]);
        }
        return helper(nums);
    }
};