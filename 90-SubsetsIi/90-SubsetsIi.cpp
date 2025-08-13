// Last updated: 8/13/2025, 3:37:06 PM
class Solution {
public:
void print(int i,vector<int>&nums,set<vector<int>>&c,vector<int>b){
    if(i==nums.size()){
        c.insert(b);
        return;
    }
    b.push_back(nums[i]);
    print(i+1,nums,c,b);
    b.pop_back();
    print(i+1,nums,c,b);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
      set<vector<int>>c;
      vector<int>b;
      print(0,nums,c,b);
      return vector<vector<int>>(c.begin(),c.end());
    }
};