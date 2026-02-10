class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int>sto;
            set<int>ste;
            for(int j=i;j<n;j++){
               if(nums[j]%2==0)ste.insert(nums[j]);
               else sto.insert(nums[j]);
               if(sto.size()==ste.size()){
                // int size=ste.size();
                count=max(count,j-i+1);
               }
            }
        }
        return count;
    }
};