class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int count=0;
        int sum2=0;
        for(int i=0;i<nums.size()-1;i++){
           sum2+=nums[i];
           int val=abs(sum-(2*sum2));
           if(val%2==0){
            count++;
           }
        }
        return count;
    }
};