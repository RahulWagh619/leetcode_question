class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorr=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            xorr=(xorr ^ nums[i]);
        }
        if(xorr!=0){
            return nums.size();
        }
        vector<int>count(31,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=30;j++){
                if((nums[i]>>j) & 1){
                    count[j]++;
                }
            }
        }
        vector<int>needed;
        for(int j=0;j<31;j++){
            if(count[j]%2==0){
                needed.push_back(j);
            }
        }
        cout<<needed.size()<<endl;
       for (int i = 0; i < n; i++) {
       for (int j = 0; j < needed.size(); j++) {
        if (((nums[i] >> needed[j]) & 1) == 1) {
            return n - 1; 
        }
    }
}
        return 0;

    }
};