class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int maxi = INT_MIN;
        int ans = 0;
        int cost = neededTime[0];
        
        for(int i = 1; i < n; i++){
            cost += neededTime[i];
            
            if(colors[i] == colors[i-1]){
                maxi = max(maxi, max(neededTime[i], neededTime[i-1]));
            }
            else{
                cost -= neededTime[i];
                if(maxi != INT_MIN){
                    ans += (cost - maxi);
                }
                cost = neededTime[i];
                maxi = INT_MIN;
            }
        }
        
        if(maxi != INT_MIN){
            ans += (cost - maxi);
        }
        
        return ans;
    }
};
