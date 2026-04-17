class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int>mpp;
        int val=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!=mpp.end()){
                val=min(val,i-mpp[nums[i]]);
            }
                string s=to_string(nums[i]);
                reverse(s.begin(),s.end());
                int k=0;
                for(int j=0;j<s.length();j++){
                    if(s[j]=='0'){
                        k++;
                    }
                    else{
                        break;
                    }
                }
                s=s.substr(k);
                int z=stoi(s);
                mpp[z]=i;
        }
        if(val==INT_MAX){
            return -1;
        }
        return val;
    }
};