class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count=1;
        int i=0;
        for(int j=1;j<prices.size();j++){
             if(prices[j]-prices[j-1]==-1){
                count+=(j-i+1);
             }
             else{
                 i=j;
                 count++;
             }
        }
        return count;
    }
};