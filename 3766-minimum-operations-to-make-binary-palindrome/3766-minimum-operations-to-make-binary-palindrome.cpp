class Solution {
public:
vector<int>val;
bool istrue(string ans){
    int i=0;
    int j=ans.length()-1;
    while(i<=j){
        if(ans[i]!=ans[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
    vector<int> minOperations(vector<int>& nums) {
        
    for(int n=1;n<=5000;n++){
    string ans = "";
        int j=(int)(log(n) / log(2));
    for (int i=j; i>=0; i--) {
        
        if (n&(1<<i)) ans += '1';
        else ans += '0';
    }
    if(istrue(ans)){
        val.push_back(n);
     }
    }
    vector<int>z;
    for(int i=0;i<nums.size();i++){
        int m=lower_bound(val.begin(),val.end(),nums[i])-val.begin();
        // int maxi=INT_MAX;
        int diff=INT_MAX;
        if(m!=val.size()){
            diff=abs(nums[i]-val[m]);
        }
        if(m-1>=0){
            diff=min(diff,abs(nums[i]-val[m-1]));
        }
        z.push_back(diff);
    }
    return z;
    }
};