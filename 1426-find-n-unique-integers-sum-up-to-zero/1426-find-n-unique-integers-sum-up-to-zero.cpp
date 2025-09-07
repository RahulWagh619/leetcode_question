class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n & 1){
            ans.push_back(0);
        }
        int half=n/2;
        for(int i=1;i<=half;i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};