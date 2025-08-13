// Last updated: 8/13/2025, 3:34:00 PM
class Solution {
public:
void subsequence(vector<int>&nums,int i,int &sum,vector<int>&b){
    if(i>=nums.size()){
        // a.push_back(b);
        // // for(int i=0;i<a.size();i++){
        // //     // int xorr1=0;
        // //     for(int j=0;j<a[i].size();j++){
        // //     //    xorr1^=a[i][j];
        // //     }
        // //     //    sum+=xorr1;
        // // }
        // for(auto k:a){
        //     cout<<k<<" ";
        // }
        //     cout<<endl;
        int x=0;
        for(int i=0;i<b.size();i++){
         x^=b[i];
        }
        sum+=x;
        return;
    }
    b.push_back(nums[i]);
    // sum2^=
    subsequence(nums,i+1,sum,b);
    b.pop_back();
    subsequence(nums,i+1,sum,b);

}
    int subsetXORSum(vector<int>& nums) {
        int i=0;
        int sum=0;
        // vector<vector<int>>a;
        vector<int>b;
        int sum2=0;
        subsequence(nums,i,sum,b);

        return sum;
    }
};