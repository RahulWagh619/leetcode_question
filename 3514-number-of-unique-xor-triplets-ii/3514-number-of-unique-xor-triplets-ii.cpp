class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st1;
        vector<int>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=(nums[i] ^ nums[j]);
                if(st1.find(val)==st1.end()){
                    v.push_back(val);
                    st1.insert(val);
                }
            }
        }
        unordered_set<int>ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<nums.size();j++){
                 int val2=(v[i] ^ nums[j]);
                 ans.insert(val2);
            }
        }
        return ans.size();
    }
};