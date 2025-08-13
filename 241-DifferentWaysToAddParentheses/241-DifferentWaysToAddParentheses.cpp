// Last updated: 8/13/2025, 3:35:51 PM
class Solution {
public:
// int dp[22][22];
vector<int>helper(string &expression,int i,int j){
    vector<int>res;
    // if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<=j;k++){
       if (expression[k] == '+' || expression[k] == '-' || expression[k] == '*') {
                vector<int> left = helper(expression, i, k - 1);
                vector<int> right = helper(expression, k + 1, j);
                for (int l : left) {
                    for (int r : right) {
                        if (expression[k] == '+') res.push_back(l + r);
                        else if (expression[k] == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
     }
    } 
    if (res.empty()) {
            res.push_back(stoi(expression.substr(i, j - i + 1)));
        }
    return res;
}
    vector<int> diffWaysToCompute(string expression) {
        // memset(dp,-1,sizeof dp);
         return helper(expression,0,expression.length()-1);
    }
};